#include <cstdlib>
#if _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define INIT_ARRAY_SIZE 8
#define GROW_FACTOR 2

void Sleep_ms(uint32_t ms)
{
#if _WIN32
    Sleep(ms);
#else
    usleep(ms*1000);
#endif
}

// puede ser cambiado para optimizar
struct MapObj {
    // aquí va cualquier tipo simple (int, float, bool, zintxx_t)
    void *data;
    size_t len;
    size_t itemLen;
    void *values;
    void (*fun)(void *item, void *values);
};

// puede ser cambiado para optimizar
struct MappingEngine {
    MapObj *items;
    size_t count;
    size_t capacity;

};

void DynamicArrayAppend(MappingEngine *engine, MapObj obj) {
    // ver si está vacío
    if (engine->items == NULL) {
        MapObj *new_items = (MapObj *)calloc(INIT_ARRAY_SIZE, sizeof(MapObj));
        if (!new_items) {
            //qué hacemos aquí?
            return;
        }
        engine->items = new_items;
        engine->capacity = INIT_ARRAY_SIZE;
        engine->count = 0;
    }
    // hacer más grande
    if (engine->capacity == 0) {
        MapObj *new_items = (MapObj *)realloc(engine->items, sizeof(MapObj)*engine->count*GROW_FACTOR);
        if (!new_items) {
            //qué hacemos aquí?
            return;
        }
        engine->capacity = GROW_FACTOR*engine->count - engine->capacity;
    }
    // meterlo
    engine->items[engine->count] = obj;
    engine->capacity--;
    engine->count++;
}

// puede ser cambiado para optimizar
void UpdateMapping(MappingEngine *engine)
{
    for(size_t mapIdx = 0; mapIdx < engine->count; mapIdx++) {
        MapObj *obj = engine->items + mapIdx;
        for(size_t objIdx = 0; objIdx < obj->len; objIdx++) {
            obj->fun((uint8_t*)obj->data + objIdx * obj->itemLen,
                     obj->values);
        }
    }
}

// puede ser cambiado para optimizar
#define AddMapping(engine, data, fun, values) \
    AddMapping_Impl(engine, data, sizeof(data)/sizeof(data[0]), \
        sizeof(data[0]), fun, (void*)values)

// puede ser cambiado para optimizar
void AddMapping_Impl(MappingEngine *engine, void *data, size_t len, uint32_t itemLen, void (*fun)(void *item, void *values), void *values)
{
    MapObj prot = {
        .data = data,
        .len = len,
        .itemLen = itemLen,
        .values = values,
        .fun = fun,
    };
    // this is vector append
    DynamicArrayAppend(engine, prot);
}

// ejemplo de map function
// void *values can be one or two values
void rangeMapping(void *item, void *values)
{
    float min = *(float*)values;
    float max = *((float*)values + 1);

    float val = *(float*)item;
    bool inrange = val > min && val < max;
    printf("value %s", inrange ? "in range\n" : "out of range\n");
}

int main()
{
    MappingEngine engine_data = {0};
    MappingEngine *engine = &engine_data;

    float toBeMappedArray[3] = {3.f, -1.f, 10.f};
    float valueRange[2] = {2.7f, 4.2f};

    for(int i = 0; i < 10; i++) {
        printf("%d\n", i);
        AddMapping(engine, toBeMappedArray, rangeMapping, &valueRange);
        Sleep_ms(10);
    }

    UpdateMapping(engine);
    return 0;
}