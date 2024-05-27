## **Bài 4.9: <u>Giá trị logic (Boolean Values)</u>**

Trong thực tế, chúng ta thường xuyên đặt ra hoặc được hỏi những câu hỏi chỉ có thể trả lời bằng "có" hoặc "không". Ví dụ: "Táo có phải là trái cây?" (Có) hoặc "Bạn có thích măng tây không?" (Không).

Tương tự, ta có thể đặt ra những câu hỏi có thể trả lời bằng "đúng" hoặc "sai". Ví dụ: "Táo là một loại trái cây" (Đúng) hoặc "Tôi thích măng tây" (Sai).

Những loại câu chỉ có hai kết quả khả thi này (có/đúng hoặc không/sai) rất phổ biến, do đó nhiều ngôn ngữ lập trình bao gồm một kiểu dữ liệu đặc biệt để xử lý chúng. Kiểu dữ liệu này được gọi là **Boolean** (Lưu ý: **Boolean** được viết hoa vì nó được đặt theo tên của nhà phát minh ra nó, George Boole).

### **Biến Boolean**

**Biến Boolean** là biến chỉ có thể có hai giá trị: `true` (đúng) và `false` (sai).

Để khai báo một biến Boolean, chúng ta sử dụng từ khóa `bool`.
>`bool b;`

Để khởi tạo hoặc gán giá trị `true` hoặc `false` cho một biến Boolean, chúng ta sử dụng các từ khóa `true` và `false`.
>```
>bool b1 { true };
>bool b2 { false };
>b1 = false;
>bool b3 {}; // mặc định khởi tạo thành false
>```

Giống như toán tử một ngôi "trừ" (`-`) có thể được sử dụng để tạo ra một số nguyên âm, toán tử logic *NOT* (`!`) có thể được sử dụng để đảo ngược giá trị Boolean từ `true` thành `false` hoặc `false` thành `true`:
>```
>bool b1 { !true }; // b1 sẽ được khởi tạo với giá trị false
>bool b2 { !false }; // b2 sẽ được khởi tạo với giá trị true
>```

Giá trị Boolean không thực sự được lưu trữ trong các biến Boolean dưới dạng các từ `"true"` hoặc `"false"`. Thay vào đó, chúng được lưu trữ dưới dạng số nguyên: `true` trở thành số nguyên `1`, và `false` trở thành số nguyên `0`. Tương tự, khi các giá trị Boolean được đánh giá, chúng không thực sự được đánh giá thành `"true"` hoặc `"false"`. Chúng được đánh giá thành các số nguyên `0` (sai) hoặc `1` (đúng). 

Vì Boolean thực sự lưu trữ các số nguyên, nên chúng được coi là một **kiểu dữ liệu giống số nguyên (integral type)**.

### **In giá trị Boolean**

Khi chúng ta in các giá trị Boolean, `std::cout` sẽ in `0` cho `false` và `1` cho `true`:
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << true << '\n'; // true được đánh giá thành 1
>    std::cout << !true << '\n'; // !true được đánh giá thành 0
>
>    bool b {false};
>    std::cout << b << '\n'; // b là false, được đánh giá thành 0
>    std::cout << !b << '\n'; // !b là true, được đánh giá thành 1
>    return 0;
>}
>```

**Kết quả in:**
>```
>1
>0
>0
>1
>```

Nếu bạn muốn `std::cout` in `"true"` hoặc `"false"` thay vì `0` hoặc `1`, bạn có thể sử dụng `std::boolalpha`. 

**Đây là một ví dụ:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << true << '\n';
>    std::cout << false << '\n';
>
>    std::cout << std::boolalpha; // in bool dưới dạng true hoặc false
>
>    std::cout << true << '\n';
>    std::cout << false << '\n';
>    return 0;
>}
>```

**Kết quả in:**
>```
>1
>0
>true
>false
>```

Bạn có thể sử dụng `std::noboolalpha` để tắt tính năng in `"true"` hoặc `"false"`.

### **Chuyển đổi từ số nguyên sang Boolean**

Khi sử dụng khởi tạo chuẩn (uniform initialization), bạn có thể khởi tạo biến bằng các giá trị số nguyên `0` (cho `false`) và `1` (cho `true`) (nhưng thực sự nên sử dụng `false` và `true` thay thế). Các giá trị số nguyên khác sẽ gây ra lỗi biên dịch:
>```
>#include <iostream>
>
>int main()
>{
>	bool bFalse { 0 }; // okay: khởi tạo thành false
>	bool bTrue  { 1 }; // okay: khởi tạo thành true
>	bool bNo    { 2 }; // error: không được phép chuyển đổi thu hẹp kiểu dữ liệu
>
>	std::cout << bFalse << bTrue << bNo << '\n';
>
>	return 0;
>}
>```

Tuy nhiên, trong bất kỳ ngữ cảnh khai báo nào cho phép chuyển đổi số nguyên sang Boolean, số nguyên `0` sẽ được chuyển đổi thành `false`, và bất kỳ số nguyên nào khác sẽ được chuyển đổi thành `true`.
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << std::boolalpha; // in bool dưới dạng true hoặc false
>	
>    bool b1 = 4 ; // khởi tạo sao chép cho phép chuyển đổi ẩn từ int sang bool
>    std::cout << b1 << '\n';
>
>    bool b2 = 0 ; // khởi tạo sao chép cho phép chuyển đổi ẩn từ int sang bool
>    std::cout << b2 << '\n';
>    
>    return 0;
>}
>```

**Kết quả in ra:**
>```
>true
>false
>```

**Lưu ý:** `bool b1 = 4;` có thể tạo ra cảnh báo. Nếu vậy, bạn cần tắt tính năng `"treating warnings as errors"` (coi cảnh báo như lỗi) để biên dịch ví dụ.

### **Nhập giá trị Boolean**

Nhập giá trị Boolean bằng `std::cin` đôi khi gây khó khăn cho người lập trình mới.

Xem xét chương trình sau:
>```
>#include <iostream>
>
>int main()
>{
>    bool b{}; // mặc định khởi tạo thành false
>    std::cout << "Nhập một giá trị Boolean: ";
>    std::cin >> b;
>    std::cout << "Bạn đã nhập: " << b << '\n';
>    
>    return 0;
>}
>```

>```
>Nhập một giá trị Boolean: true
>Bạn đã nhập: 0
>```

Điều gì đã xảy ra vậy?

Lý do là `std::cin` chỉ chấp nhận hai đầu vào cho biến Boolean: `0` (sai) và `1` (đúng). Bất kỳ đầu vào nào khác sẽ khiến `std::cin` hoạt động không chính xác mà không báo lỗi. Trong trường hợp này, vì chúng ta nhập `"true"`, `std::cin` đã sai sót và gán giá trị `false` cho biến `b`. Do đó, khi `std::cout` in giá trị của `b`, nó hiển thị `0`.

Để cho phép `std::cin` chấp nhận `"false"` và `"true"` làm đầu vào, tùy chọn `std::boolalpha` phải được bật:
>```
>#include <iostream>
>
>int main()
>{
>    bool b{};
>    std::cout << "Nhập một giá trị Boolean: ";
>
>    // Cho phép người dùng nhập "true" hoặc "false" cho giá trị Boolean
>    // Phân biệt chữ hoa chữ thường, ví dụ: True hoặc TRUE sẽ không hoạt động
>    std::cin >> std::boolalpha;
>    std::cin >> b;
>
>    std::cout << "Bạn đã nhập: " << b << '\n';
>
>    return 0;
>}

>**Cảnh báo**<br>
>Khi bật `std::boolalpha`, `0` và `1` sẽ không còn được coi là đầu vào Boolean mà sẽ được chuyển đổi thành `"false"` (cùng với bất kỳ đầu vào nào khác ngoài `"true"`).\
>Bật `std::boolalpha` chỉ cho phép chấp nhận `"true"` và `"false"` viết thường. Các biến thể viết hoa sẽ không được chấp nhận.


### **Giá trị trả về Boolean (Boolean Return Values)**

Giá trị Boolean thường được sử dụng làm giá trị trả về cho các hàm kiểm tra xem một điều kiện nào đó là đúng hay sai. Các hàm này thường được đặt tên bắt đầu bằng từ **`is`** (ví dụ: `isEqual`) hoặc **`has`** (ví dụ: `hasCommonDivisor`).

**Xem xét ví dụ sau về hàm `isEqual`:**
>```
>#include <iostream>
>
>// Trả về true nếu x và y bằng nhau, ngược lại trả về false
>bool isEqual(int x, int y)
>{
>    return x == y; // toán tử == trả về true nếu x bằng y, ngược lại trả về false
>}
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x{};
>    std::cin >> x;
>
>    std::cout << "Nhập một số nguyên khác: ";
>    int y{};
>    std::cin >> y;
>
>    std::cout << std::boolalpha; // in bool dưới dạng true hoặc false
>
>    std::cout << x << " và " << y << " có bằng nhau không? ";
>    std::cout << isEqual(x, y) << '\n'; // sẽ trả về true hoặc false
>
>    return 0;
>}
>```

**Đây là kết quả chạy của chương trình:**
>```
>Nhập một số nguyên: 5
>Nhập một số nguyên khác: 5
>5 và 5 có bằng nhau không? true

>```
>Nhập một số nguyên: 6
>Nhập một số nguyên khác: 4
>6 và 4 có bằng nhau không? false
>```

**Giải thích hoạt động:**

Đầu tiên, chương trình đọc các giá trị số nguyên cho `x` và `y`. Tiếp theo, biểu thức `isEqual (x, y)` được tính toán. Trong lần chạy đầu tiên, điều này dẫn đến việc gọi hàm `isEqual(5, 5)`. Bên trong hàm đó, `5 == 5` được đánh giá, tạo ra giá trị `true`. Giá trị `true` được trả về cho trình gọi để được in bởi `std::cout`. Trong lần chạy thứ hai, lệnh gọi `isEqual(6, 4)` trả về giá trị `false`.

Mặc dù ban đầu giá trị Boolean có thể hơi khó làm quen, nhưng một khi bạn hiểu được cách thức hoạt động của chúng, bạn sẽ thấy chúng đơn giản và hữu ích! Giá trị Boolean đóng vai trò quan trọng trong ngôn ngữ lập trình C++, và bạn sẽ sử dụng chúng nhiều hơn tất cả các kiểu dữ liệu cơ bản khác cộng lại!
