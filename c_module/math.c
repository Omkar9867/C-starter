#include "math.h"

// vector_h Add(vector_h v1,vector_h v2){
//     vector_h result;
//     result.x = v1.x + v2.x;
//     result.y = v1.y + v2.y;
//     return result;
// }
// We can do this but will get the stack memory and heap memory error.
// So we will use the pointer to the structure.

void Add(vector_h* out, const vector_h* in){
    out->x = out->x + in->x;
    out->y = out->y + in->y;
}