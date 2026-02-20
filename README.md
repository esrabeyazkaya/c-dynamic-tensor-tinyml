# C-Dynamic-Tensor-TinyML

Gömülü sistemler için bellek optimize edilmiş dinamik Tensor implementasyonu (C dili).

## 📌 Proje Amacı
Bu projede, RAM kısıtlaması olan gömülü sistemler (mikrodenetleyiciler) için bellek dostu, dinamik bir Tensor veri yapısı tasarlanmıştır. Temel amaç, aynı Tensor yapısı içinde ihtiyaca göre farklı veri tiplerini (`FLOAT32` ve `INT8`) kullanarak bellek kullanımındaki dramatik farkı uygulamalı olarak göstermektir.

## 🧠 Tensor Nedir?
Tensor, makine öğrenmesi ve yapay zeka modellerinde sayısal verileri saklayan çok boyutlu bir veri yapısıdır. Yapay zeka uygulamalarında giriş verileri (inputs) ve ağırlıklar (weights) tensor formunda tutulur. Bu projede, bellek yönetimini göstermek amacıyla temel seviyede 1 boyutlu bir tensor (dizi) örneği oluşturulmuştur.

## 🛠 Kullanılan C Yapıları

* **Enum (Enumeration):** Tensor’un o anki veri tipini (`TENSOR_FLOAT32`, `TENSOR_INT8`) dinamik olarak belirlemek ve takip etmek için kullanılmıştır.
* **Union:** Gömülü sistemlerde bellek tasarrufunun kalbidir. Aynı bellek adresi içinde farklı pointer tiplerini saklamak için kullanılmıştır. Bu sayede tek bir Tensor, bellekte fazladan yer işgal etmeden hem float hem de int8 veriyi tutabilmektedir.

## 📉 Quantization (Kuantizasyon) Nedir?
Quantization, `float32` gibi yüksek hassasiyetli ve bellekte çok yer kaplayan sürekli veri tiplerini, matematiksel bir ölçekleme (scale) işlemiyle daha küçük veri tiplerine (`int8`) dönüştürme işlemidir. 
* Örnek: `1.5` → `1`, `2.7` → `2`
* **Sonuç:** Bu dönüşümde virgülden sonraki hassasiyet bir miktar azalır, ancak bellek kullanımı ve işlem hızı gömülü sistemler için hayati derecede iyileşir.

## 📊 Bellek Karşılaştırması
Projedeki 4 elemanlı bir matris için bellek tüketimi şu şekildedir:
* **FLOAT32:** 16 byte
* **INT8:** 4 byte
> **Sonuç:** `INT8` formatı ve kuantizasyon sayesinde, `FLOAT32`'ye göre **%75 oranında (4 kat) bellek tasarrufu** sağlanmıştır.

## 🚀 Sonuç
Bu projede;
1. Dinamik bellek tahsisi (memory allocation),
2. C dilinde `Enum` ve `Union` yapıları ile bellek optimizasyonu,
3. Kayan noktalı sayılar üzerinde basit Kuantizasyon işlemi başarıyla uygulanmış ve TinyML felsefesi temel seviyede gösterilmiştir.

## 🎥 Demo ve Sunum Videosu
Projenin çalıştığını, bellek yönetimini ve Debugger kullanımını gösterdiğim sunum videosuna aşağıdan ulaşabilirsiniz:
