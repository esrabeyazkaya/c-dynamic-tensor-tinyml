# c-dynamic-tensor-tinyml
Gömülü sistemler için bellek optimize edilmiş dinamik Tensor implementasyonu (C dili).
# C Dilinde Basit Tensor Implementasyonu

## Proje Amacı

Bu projede, bellek kapasitesi sınırlı olan gömülü sistemler için basit bir Tensor veri yapısı tasarlanmıştır.

Amaç, aynı Tensor yapısı içinde farklı veri tiplerini (FLOAT32 ve INT8) kullanarak bellek kullanım farkını göstermektir.



## Tensor Nedir?

Tensor, sayısal verileri saklayan çok boyutlu bir veri yapısıdır.

Yapay zeka uygulamalarında giriş verileri ve ağırlıklar tensor olarak tutulur.

Bu projede basit bir 1 boyutlu tensor (dizi) örneği yapılmıştır.


## Kullanılan Yapılar

### Enum

Tensor’un veri tipini belirlemek için kullanılmıştır.

### Union

Aynı veri yapısı içinde farklı pointer tiplerini saklamak için kullanılmıştır.

Bu sayede tek bir Tensor hem float hem de int8 veri tutabilmektedir.

---

## Quantization Nedir?

Quantization, float gibi yüksek hassasiyetli bir veri tipini daha küçük bir veri tipine (int8) dönüştürme işlemidir.

Örnek:

1.5 → 1  
2.7 → 2  

Bu dönüşümde hassasiyet azalır ancak bellek kullanımı düşer.


## Bellek Karşılaştırması

4 eleman için:

- FLOAT32 → 16 byte
- INT8 → 4 byte

INT8 veri tipi, FLOAT32’ye göre 4 kat daha az bellek kullanır.


## Sonuç

Bu projede:

- Dinamik bellek kullanımı (malloc)
- Enum ve Union yapıları
- Basit quantization işlemi
- Bellek karşılaştırması

gösterilmiştir.

Bu çalışma TinyML mantığını temel seviyede göstermektedir.
