## **Bài 4.2: <u>`void`</u>** 

### **`void` - Kiểu dữ liệu đơn giản nhất**

`void` là một trong những kiểu dữ liệu dễ giải thích nhất. Về cơ bản, `void` có nghĩa là **"không kiểu"**!

`void` là ví dụ đầu tiên về một **kiểu dữ liệu không đầy đủ (incomplete type)**. **Kiểu dữ liệu không đầy đủ** là kiểu đã được khai báo nhưng chưa được định nghĩa. Trình biên dịch biết về sự tồn tại của các kiểu như vậy, nhưng không có đủ thông tin để xác định cần phân bổ bao nhiêu bộ nhớ cho các đối tượng của kiểu đó. `void` được thiết kế là không đầy đủ vì nó đại diện cho sự thiếu kiểu, do đó không thể được định nghĩa.

**Kiểu dữ liệu không đầy đủ không thể được khởi tạo:**
>```
>void value; // Không hợp lệ, biến không thể được khai báo với kiểu không đầy đủ void
>```

**`void` thường được sử dụng trong một số ngữ cảnh khác nhau:**

### **Hàm không trả về giá trị**

Thông thường nhất, `void` được sử dụng để chỉ rằng một hàm không trả về giá trị:

>```
>void writeValue(int x) // void ở đây nghĩa là không có giá trị trả về
>{
>    std::cout << "Giá trị của x là: " << x << '\n';
>    // Không có lệnh return, vì hàm này không trả về giá trị
>}
>```

Nếu bạn sử dụng lệnh `return` để cố gắng trả về giá trị trong một hàm như vậy, sẽ dẫn đến lỗi biên dịch:

>```
>void noReturn(int x) // void ở đây nghĩa là không có giá trị trả về
>{
>    std::cout << "Giá trị của x là: " << x << '\n';
>
>    return 5; // Lỗi
>}
>```

Trên Visual Studio 2017, lỗi này sẽ hiển thị:
>```
>error C2562: 'noReturn': 'void' function returning a value
>```

### **Không khuyến khích: Hàm không nhận tham số**

Trong C, `void` được sử dụng để chỉ rằng một hàm không nhận bất kỳ tham số nào:

>```
>int getValue(void) // void ở đây nghĩa là không có tham số
>{
>    int x{};
>    std::cin >> x;
>
>    return x;
>}
>```

Mặc dù đoạn code này có thể biên dịch trong C++ (vì lý do tương thích ngược), cách sử dụng từ khóa `void` này được coi là không khuyến khích trong C++. Đoạn code sau đây tương đương và được ưu tiên hơn trong C++:

>```
>int getValue() // Danh sách tham số trống ngầm định là void
>{
>    int x{};
>    std::cin >> x;
>
>    return x;
>}
>```

>**Thực hành tốt nhất:**<br>
>Sử dụng danh sách tham số trống thay vì `void` để chỉ rằng một hàm không có tham số.

### **Những cách sử dụng `void` khác**

Từ khóa `void` có cách sử dụng thứ ba (nâng cao hơn) trong C++, được đề cập trong phần 19.5 - Con trỏ `void`. Vì chúng ta chưa học về con trỏ, bạn không cần lo lắng về trường hợp này hiện tại.
