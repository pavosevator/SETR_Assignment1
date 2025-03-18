# Set the source files that make up the library
set(MyDLLSRC
 mydll.h mydll.c
)
# Set the library type (can be static or dynamic )
set(LIB_TYPE STATIC)

# Create the library
add_library (MyDLLLib ${LIB_TYPE} ${MyDLLSRC})
