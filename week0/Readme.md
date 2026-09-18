## Week 0 training month excercise

Ejercicio: Hacer un `.map()` extenso en C/C++

Idea:

```cpp
#if _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

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
    //DynamicArray_Append(engine, prot);
}

// ejemplo de map function
// void *values can be one or two values
void rangeMapping(void *item, void *values)
{
    float min = *(float*)values;
    float max = *((float*)values + 1);

    float val = *(float*)item;
    bool inrange = val > min && val < max;
    printf("value %s", inrange ? "in range" : "out of range");
}

int main()
{
    MappingEngine engine_data = {0};
    MappingEngine *engine = &engine_data;

    float toBeMappedArray[12] = {0};
    float valueRange[2] = {2.7f, 4.2f};
    AddMapping(engine, toBeMappedArray, rangeMapping, &valueRange);

    for(;;) {
        UpdateMapping(engine);
        Sleep_ms(100);
    }

    return 0;
}
```
