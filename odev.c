#include <stdio.h>
#include <stdlib.h>

/* -------- ENUM -------- */

typedef enum {
    FLOAT32,
    INT8
} TensorType;

/* -------- UNION -------- */

typedef union {
    float* f32;
    signed char* i8;   // int8_t yerine signed char
} TensorData;

/* -------- STRUCT -------- */

typedef struct {
    TensorData data;
    int size;
    TensorType type;
} Tensor;

/* -------- CREATE -------- */

Tensor createTensor(int size, TensorType type) {
    Tensor t;
    t.size = size;
    t.type = type;

    if (type == FLOAT32) {
        t.data.f32 = (float*)malloc(size * sizeof(float));
    } else {
        t.data.i8 = (signed char*)malloc(size * sizeof(signed char));
    }

    return t;
}

/* -------- SET -------- */

void setValue(Tensor* t, int index, float value) {

    if (t->type == FLOAT32) {
        t->data.f32[index] = value;
    }
    else {
        t->data.i8[index] = (signed char)value;  // Quantization
    }
}

/* -------- PRINT -------- */

void printTensor(Tensor* t) {

    int i;

    for (i = 0; i < t->size; i++) {

        if (t->type == FLOAT32) {
            printf("%.2f ", t->data.f32[i]);
        }
        else {
            printf("%d ", t->data.i8[i]);
        }
    }

    printf("\n");
}

/* -------- MEMORY -------- */

int memoryUsage(Tensor* t) {

    if (t->type == FLOAT32)
        return t->size * sizeof(float);
    else
        return t->size * sizeof(signed char);
}

/* -------- MAIN -------- */

int main() {

    Tensor t1 = createTensor(4, FLOAT32);
    setValue(&t1, 0, 1.5);
    setValue(&t1, 1, 2.7);
    setValue(&t1, 2, 3.9);
    setValue(&t1, 3, 4.2);

    printf("FLOAT32 Tensor:\n");
    printTensor(&t1);
    printf("Memory: %d bytes\n\n", memoryUsage(&t1));

    Tensor t2 = createTensor(4, INT8);
    setValue(&t2, 0, 1.5);
    setValue(&t2, 1, 2.7);
    setValue(&t2, 2, 3.9);
    setValue(&t2, 3, 4.2);

    printf("INT8 Tensor (Quantized):\n");
    printTensor(&t2);
    printf("Memory: %d bytes\n\n", memoryUsage(&t2));

    free(t1.data.f32);
    free(t2.data.i8);

    return 0;
}
