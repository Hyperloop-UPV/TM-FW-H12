

int (*fun)();

typedef struct node node;
struct node {
    node *next;
    int data;
}


struct name {

};

void fun(int arr[])
{
    sizeof(
        arr
    ); // 8
}

int arr[10];
int arr2[10][10];
int arr2_v2[10*10];

arr2[y][x];
arr2_v2[y + x*width];


std::array<int, 10> arr;


#pragma pack(push)

struct bitmap_in_memory {
    uint32_t width, height;
    uint8_t pixeldensity;
    //uint8_t padding[3];
    uint32_t *data;
};

#pragma pack(pop)



#define SOME_CONST (myarray->a + 10)

int a = SOME_CONST * 10;


#define MACRO_LIKE_FUNCTION(s) ((s)->length)

struct { int length; } some_struct;

MACRO_LIKE_FUNCTION(&some_struct)

((&some_struct)->length)


#define DEFINE_ARRAY(name, type) \
    struct name ## _arr {  \
        type *data;        \
        size_t length;     \
    }

DEFINE_ARRAY(int, int);


#define LOC_STR __FILE__"(" stringify(__LINE__)")"

#if !defined(stringify)
# define stringify_(a) #a
# define stringify(a) stringify_(a)
#endif
#if !defined(glue)
# define glue_(a,b) a##b
# define glue(a,b) glue_(a,b)
#endif

// __COUNTER__

#define X()

int main()
{
    char *file = LOC_STR;
    "main"
    char function[] = "main";
    printf(LOC_STR ": %s", __FUNCTION__);

    struct {  
        type *data;        
        size_t length;     
    } arr = {
        .data = mimemory,
    };

    #define CmdAppend(cmd, ...) \
    DaAppendMany(cmd, \
                  ((const char*[]){__VA_ARGS__}), \
                  (sizeof((const char*[]){__VA_ARGS__})/sizeof(const char*)))

    vl_cmd cmd = {0};
    CmdAppend(&cmd, "gcc", "main.c", "-o", "out");

    return 0;
}

void UpdateMapping(MappingEngine *engine, bool flag);

template<bool print_or_not>
inline void dothing()
{
    if constexpr (print_or_not) {
        printf("did print\n");
    } else if constexpr (true) {
        printf("did not print or maybe did?\n");
    }


}

void dothing__true()
{
    printf("did print\n");
}

void dothing__false()
{
    printf("did not print or maybe did?\n");
}

void fun2()
{
    // dothing true was called ! -> make new function in binary called something similar to dothing__true
    dothing<true>();
    // dothing false was called ! -> make new function in binary called something similar to dothing__false
    dothing<false>();
}

// NO se puede porque C++ no sabe como de grande es esto (da igual si se usa el valor del template o no)
MapObj<T> maps[10];
// Se puede porque todos los valores de maps son del mismo tipo
MapObj<10> maps[10];
