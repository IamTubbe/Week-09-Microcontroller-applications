# 📚 Week 09: ESP32 GPIO Architecture

> **หัวข้อ:** การศึกษาสถาปัตยกรรม ESP32 โดยเฉพาะระบบ GPIO และ Dual-Core Processing

---

## 📋 เอกสารการเรียนรู้

### 📖 เอกสารหลัก
- 📚 **[ใบความรู้ ESP32 GPIO Architecture](ESP32-GPIO-Knowledge-Sheet.md)**  
  เนื้อหาความรู้ครบถ้วนเกี่ยวกับสถาปัตยกรรม ESP32

- 📋 **[ใบงาน ESP32 GPIO Analysis](ESP32-GPIO-Worksheet.md)**  
  แบบฝึกหัดและการประเมินผล (100 คะแนน, 90 นาที)

---
### 🚀 งาน Lab ที่ส่ง :

งานหลักอยู่ที่โฟลเดอร์: **[`my_led_lab/`](./my_led_lab/)**

<details>
<summary>คลิกเพื่อดูรายละเอียดการทำงาน</summary>

* **รวมโค้ดในไฟล์เดียว**: ผมได้รวมโค้ดทั้ง 4 ขั้นตอน (Lab 1.1, 1.2, 1.3, และ Lab 2) ไว้ในไฟล์ `my_led_lab/main/main.c` ไฟล์เดียว
  *      Lab 1.1 (LED ON) / #define CURRENT_STEP 1
  *      Lab 1.2 (LED OFF) / #define CURRENT_STEP 2
  *      Lab 1.3 (LED Blink) / #define CURRENT_STEP 3
  *      Lab 2 (PWM Breathing) / #define CURRENT_STEP 4
* **วิธีสลับ Lab**: อาจารย์สามารถสลับการทำงานได้โดยการแก้ไข `#define CURRENT_STEP` ที่ด้านบนของไฟล์ `main.c`
</details>

---
## 📁 โครงสร้างไฟล์
```
Week-09-Microcontroller-applications/
├── 📚 ESP32-GPIO-Knowledge-Sheet.md    # ใบความรู้
├── 📋 ESP32-GPIO-Worksheet.md          # ใบงาน
├── 📖 README.md                        # ไฟล์นี้
├── 🛠️ auto_render_dot.ps1              # สคริปต์ Auto-render
├── 📂 image-src/                       # ไฟล์ต้นฉบับไดอะแกรม
├── 📂 images/                          # ไฟล์ภาพที่ render แล้ว
├── 📂 examples/                        # ตัวอย่างและเอกสารอ้างอิง 🤫
└── 📂 .vscode/                         # VS Code settings
```

## 🎯 จุดประสงค์การเรียนรู้

หลังจากศึกษาเนื้อหาในสัปดาห์นี้แล้ว ผู้เรียนจะสามารถ:

1. **🧠 เข้าใจสถาปัตยกรรม** อธิบายโครงสร้างและการทำงานของ ESP32 Dual-Core System
2. **🔌 วิเคราะห์ GPIO** เข้าใจระบบ GPIO Matrix และการ Multiplexing
3. **⚙️ ประยุกต์ใช้** วางแผนการใช้ GPIO pins และ Peripheral อย่างมีประสิทธิภาพ
4. **🛠️ เขียนโค้ด** กำหนดค่าและควบคุม GPIO ด้วย ESP-IDF
5. **🔧 แก้ปัญหา** วินิจฉัยและแก้ไขปัญหาที่เกี่ยวข้องกับ GPIO
---

## 📚 เอกสารอ้างอิง

### 📖 Documentation
- [ESP32 Technical Reference Manual](https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf)
- [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/)
- [GPIO & RTC GPIO - ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html)

### 🛠️ Development Tools
- [ESP-IDF Getting Started](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/)
- [VS Code ESP-IDF Extension](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension)

---

*📅 อัปเดตล่าสุด: September 2025*  
*👨‍💻 พัฒนาโดย: Microcontroller Applications Course Team*  
*📘 เวอร์ชัน: 1.0*
