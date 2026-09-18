1. Tipos, incluído punteros a función - `int (*fun)()`
1.1. Arrays en C/C++ y como un `int arr[10]` cuando lo pasas a una función se degenera a un `int *`
1.2. (mini explicación de pq std::array no va así)
1.3. mini apunte sobre #pragma pack y similar
2. Metaprogramación 1; Macros - que se puede hacer y que no (definir una macro dentro de otra)
2.1. XList macros
2.2. `stringify`, `glue`, `__FILE__`, `__LINE__`, `__COUNTER__`, `__FUNCTION__` que no funciona igual pq es un `char __FUNCTION__[]` en vez de un literal como `__FILE__` (importante)
2.3. funciones con argumentos por defecto o no obligatorios en C
2.4. generación de tipos/funciones en base a macros
2.5. mini explicación de:
```c
#define AppendStrings(list, ...) \
    AppendStrings_impl(list, \
        ((const char*[]){__VA_ARGS__}), \
        (sizeof((const char*[]){__VA_ARGS__})/sizeof(const char*)))
```
3. `_Generic` y como no es realmente generics, si no function overloading (exclusivo de C)
4. Metaprogramación 2; Templates, constexpr, consteval
4.1. Menciones sin necesidad de mostrar: loop en tiempo de compilación (no es loop unrolling)
5. Uso del compilador, flags usuales, flags importantes (como debug info o warnings)
