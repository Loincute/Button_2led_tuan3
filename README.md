# Dự án: Điều khiển 2 LED bằng OneButton trên ESP32

## 📖 Mô tả
Dự án sử dụng **thư viện OneButton** để điều khiển **2 LED rời** bằng **một nút nhấn duy nhất**.  

Các chức năng:  
- **Single Click** → Bật / tắt LED đang được chọn.  
- **Double Click** → Chuyển chế độ điều khiển giữa LED1 và LED2.  
- **Long Press (>1s)** → Làm LED đang chọn nhấp nháy với chu kỳ 200ms.  

## 🛠️ Phần cứng
- **ESP32 DevKit**.  
- **LED1**: nối vào GPIO2 (qua điện trở 220Ω).  
- **LED2**: nối vào GPIO25 (qua điện trở 220Ω).  
- **Button**: nối vào GPIO26, dùng `INPUT_PULLUP` (một chân nối GND, một chân nối vào GPIO18).  

## 💻 Phần mềm
- **PlatformIO** (Arduino framework).  
- **Thư viện**: [OneButton](https://github.com/mathertel/OneButton).  

## 🚀 Cách chạy
1. Clone project về máy:  
   ```bash
   https://github.com/Loincute/Button_2led_tuan3/edit/master/test/README
   cd Button_2led
2. Mở bằng VS Code + PlatformIO.
3. Upload code lên ESP32 và mở Serial Monitor để quan sát log.
