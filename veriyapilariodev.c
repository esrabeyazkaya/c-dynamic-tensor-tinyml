#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Desteklenen veri tipleri
typedef enum {
    TENSOR_FLOAT32,
    TENSOR_FLOAT16, // Bellekte 16 bit yer tutmasý için uint16_t kullanýyoruz
    TENSOR_INT8
} TensorDataType;

// Union: Bellek tasarrufu saðlayan asýl yapý. 
// Ayný anda sadece biri dolu olabilir.
typedef union {
    float* f32_data;
    uint16_t* f16_data;
    int8_t* i8_data;
} TensorData;

// Gömülü sistemler için Dinamik Tensör Yapýsý
typedef struct {
    TensorDataType type;
    int rows;
    int cols;
    TensorData data;
} Tensor;

// Float32 dizisini Int8'e çeviren Quantization Fonksiyonu
void quantize_f32_to_i8(float* input, int8_t* output, int size, float scale) {
    int i; // C99 oncesi derleyiciler icin degiskeni disarida tanimladik
    for (i = 0; i < size; i++) {
        // Deðeri scale'e böl ve yuvarla
        int quantized_val = (int)round(input[i] / scale);
        
        // 8-bit sýnýrlarýna kýrpma (Clipping)
        if (quantized_val > 127) quantized_val = 127;
        if (quantized_val < -128) quantized_val = -128;
        
        output[i] = (int8_t)quantized_val;
    }
}

int main() {
    printf("--- TinyML Gomulu Tensor ve Quantization Demosu ---\n");

    int rows = 2, cols = 2;
    int total_elements = rows * cols;
    int i; // Dongu degiskeni

    // Orijinal Float32 verisi (Sensörden gelen ham veri gibi düþünelim)
    float raw_data[] = {2.5f, -1.2f, 5.0f, -3.8f};
    
    // Tensörümüzü Float32 olarak baþlatalým
    Tensor my_tensor;
    my_tensor.rows = rows;
    my_tensor.cols = cols;
    my_tensor.type = TENSOR_FLOAT32;
    my_tensor.data.f32_data = raw_data;

    printf("\n[Float32 Matris Durumu]:\n");
    for(i=0; i<total_elements; i++) {
        printf("%f ", my_tensor.data.f32_data[i]);
    }

    // Quantization Ýþlemi (Scale = 0.05 varsayalým)
    float scale = 0.05f;
    int8_t quantized_buffer[4]; // Sadece 4 byte yer kaplar!
    
    quantize_f32_to_i8(my_tensor.data.f32_data, quantized_buffer, total_elements, scale);

    // Tensör tipini Int8'e dönüþtürüp bellekteki yeni adresi gösteriyoruz
    my_tensor.type = TENSOR_INT8;
    my_tensor.data.i8_data = quantized_buffer;

    printf("\n\n[Int8 Quantized Matris Durumu (RAM Tasarrufu Saglandi!)]:\n");
    for(i=0; i<total_elements; i++) {
        printf("%d ", my_tensor.data.i8_data[i]);
    }
    printf("\n\nIslem tamamlandi.\n");
    
    // ekranin hemen kapanmamasi icin:
    system("pause"); 

    return 0;
}
