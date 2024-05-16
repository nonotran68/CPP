## **Bài 2.1: <u>Giới thiệu về hàm</u>**

Trong chương trước, chúng ta đã định nghĩa hàm là một tập hợp các câu lệnh được thực thi tuần tự. Mặc dù điều đó hoàn toàn đúng, nhưng định nghĩa đó không cung cấp nhiều thông tin chi tiết về lý do tại sao hàm lại hữu ích. Hãy cập nhật định nghĩa của chúng ta: **Hàm** là một chuỗi các câu lệnh có thể tái sử dụng được thiết kế để thực hiện một công việc cụ thể.

Bạn đã biết rằng mọi chương trình thực thi đều phải có một hàm được đặt tên là `main` (chính là nơi chương trình bắt đầu thực thi khi được chạy). Tuy nhiên, khi chương trình bắt đầu trở nên dài hơn, việc đặt tất cả code bên trong hàm main sẽ ngày càng khó quản lý. Hàm cung cấp một cách để chúng ta chia nhỏ chương trình thành các khối nhỏ, mô-đun dễ dàng tổ chức, kiểm tra và sử dụng hơn. Hầu hết các chương trình sử dụng nhiều hàm. Thư viện chuẩn C++ đi kèm với rất nhiều hàm đã được viết sẵn để bạn sử dụng - tuy nhiên, việc viết hàm của riêng bạn cũng rất phổ biến. Các hàm do bạn tự viết được gọi là **hàm do người dùng định nghĩa (user-defined functions).**

Hãy xem xét một trường hợp có thể xảy ra trong thực tế: bạn đang đọc sách, thì bạn nhớ ra mình cần gọi điện thoại. Bạn đánh dấu trang sách, thực hiện cuộc gọi điện thoại và khi kết thúc cuộc gọi, bạn quay lại vị trí đã đánh dấu và tiếp tục đọc sách chính xác từ nơi bạn dừng lại.

Các chương trình C++ cũng có thể hoạt động theo cách tương tự. Một chương trình sẽ thực thi các câu lệnh tuần tự bên trong một hàm khi nó gặp một lời gọi hàm. **Lời gọi hàm** là một biểu thức yêu cầu CPU tạm dừng hàm hiện tại và thực thi một hàm khác. CPU “đánh dấu” tại điểm thực thi hiện tại, sau đó gọi (thực thi) hàm được đặt tên trong lời gọi hàm. Khi hàm được gọi kết thúc, CPU quay trở lại điểm đã đánh dấu và tiếp tục thực thi.

**Hàm khởi tạo lời gọi hàm được gọi là hàm gọi (caller), còn hàm được gọi bởi caller được gọi là callee (hay hàm được gọi).**

### **Hàm do người dùng định nghĩa** 

Trước tiên, hãy bắt đầu với cú pháp cơ bản nhất để định nghĩa một hàm do người dùng định nghĩa. Trong vài bài học tiếp theo, tất cả các hàm do người dùng định nghĩa sẽ có dạng sau:

>```
>returnType functionName() // Đây là tiêu đề hàm (thông báo cho trình biên dịch về sự tồn tại của hàm)
>{
>    // Đây là thân hàm (thông báo cho trình biên dịch hàm này làm gì)
>}
>```

Dòng đầu tiên được gọi không chính thức là **tiêu đề hàm (function header)**, nó thông báo cho trình biên dịch về sự tồn tại của một hàm, tên của hàm và một số thông tin khác mà chúng ta sẽ đề cập trong các bài học tiếp theo (như kiểu trả về và kiểu tham số).

Trong bài học này, chúng ta sẽ sử dụng **kiểu trả về (`returnType`)** là `int` (cho hàm `main()`) hoặc `void` (nếu không cần kiểu). Hiện tại, đừng lo lắng về chúng, vì chúng ta sẽ nói thêm về kiểu trả về và giá trị trả về trong bài học tiếp theo **(2.2 - Giá trị trả về của hàm (hàm trả về giá trị)).**

Giống như biến có tên, các hàm do người dùng định nghĩa cũng có tên. **Tên hàm (functionName)** là tên (định danh) của hàm do người dùng định nghĩa của bạn.

Dấu ngoặc đơn sau định danh cho biết với trình biên dịch rằng chúng ta đang định nghĩa một hàm.

Các dấu ngoặc nhọn và các câu lệnh bên trong được gọi là **thân hàm (function body).** Đây là nơi chứa các câu lệnh xác định chức năng của hàm của bạn.

Dưới đây là một chương trình mẫu cho thấy cách định nghĩa và gọi một hàm mới:

>```
>#include <iostream> // for std::cout
>
>// Định nghĩa hàm do người dùng định nghĩa doPrint()
>void doPrint() // doPrint() là hàm được gọi trong ví dụ này
>{
>    std::cout << "In doPrint()\n";
>}
>
>// Định nghĩa hàm main()
>int main()
>{
>    std::cout << "Starting main()\n";
>    doPrint(); // Tạm dừng main() bằng cách thực hiện một lời gọi hàm đến doPrint(). main() là hàm gọi.
>    std::cout << "Ending main()\n"; // câu lệnh này được thực thi sau khi doPrint() kết thúc
>
>    return 0;
>}
>```


Chương trình này tạo ra đầu ra sau:
>```
>Starting main()
>In doPrint()
>Ending main()
>```

Chương trình này bắt đầu thực thi ở đầu hàm `main`, và dòng đầu tiên được thực thi sẽ in ra `Starting main()`.

Dòng thứ hai trong `main` là một lời gọi hàm đến hàm `doPrint`. Chúng ta gọi hàm `doPrint` bằng cách thêm một cặp dấu ngoặc đơn vào tên hàm như thế này: `doPrint()`.<br>
Lưu ý rằng nếu bạn quên dấu ngoặc đơn, chương trình của bạn có thể không biên dịch được (và nếu có, thì hàm sẽ không được gọi).

>**Cảnh báo** <br>
>Đừng quên thêm dấu ngoặc đơn `()` sau tên hàm khi thực hiện lời gọi hàm.

Vì một lời gọi hàm đã được thực hiện, việc thực thi các câu lệnh trong `main` bị tạm dừng và thực thi nhảy đến đầu của hàm được gọi `doPrint`. Dòng đầu tiên (và duy nhất) trong `doPrint` in ra `In doPrint()`. Khi `doPrint` kết thúc, việc thực thi quay trở lại hàm gọi (ở đây: hàm `main`) và tiếp tục từ điểm dừng lại. Do đó, câu lệnh tiếp theo được thực thi trong `main` in ra `Ending main()`.

### **Gọi hàm nhiều lần**

Một điều hữu ích về hàm là chúng có thể được gọi nhiều lần. Đây là một chương trình minh họa điều này:

>```
>#include <iostream> // for std::cout
>
>void doPrint()
>{
>    std::cout << "In doPrint()\n";
>}
>
>// Định nghĩa hàm main()
>int main()
>{
>    std::cout << "Starting main()\n";
>    doPrint(); // doPrint() được gọi lần đầu tiên
>    doPrint(); // doPrint() được gọi lần thứ hai
>    std::cout << "Ending main()\n";
>
>    return 0;
>}
>```

Chương trình này tạo ra đầu ra sau:
>```
>Starting main()
>In doPrint()
>In doPrint()
>Ending main()
>```

Vì `doPrint` được gọi hai lần bởi `main`, `doPrint` thực thi hai lần và `In doPrint()` được in ra hai lần (một lần cho mỗi lời gọi).

### **Hàm có thể gọi hàm khác, hàm khác lại gọi hàm khác**

Bạn đã thấy rằng hàm `main` có thể gọi một hàm khác (chẳng hạn như hàm `doPrint` trong ví dụ ở trên). Bất kỳ hàm nào cũng có thể gọi bất kỳ hàm nào khác. Trong chương trình sau, hàm `main` gọi hàm `doA`, hàm `doA` lại gọi hàm `doB`:

>```
>#include <iostream> // for std::cout
>
>void doB()
>{
>    std::cout << "In doB()\n";
>}
>
>
>void doA()
>{
>    std::cout << "Starting doA()\n";
>
>    doB();
>
>.    std::cout << "Ending doA()\n";
>}
>
>// Định nghĩa hàm main()
>int main()
>{
>    std::cout << "Starting main()\n";
>
>    doA();
>
>    std::cout << "Ending main()\n";
>
>    return 0;
>}
>```

Chương trình này tạo ra đầu ra sau:
>```
>Starting main()
>Starting doA()
>In doB()
>Ending doA()
>Ending main()
>```

**Giải thích:**

- Chương trình bắt đầu thực thi tại hàm `main`.
- Dòng đầu tiên trong main in ra `"Starting main()"`.
- Tiếp theo, `main` gọi hàm `doA` bằng cách sử dụng `doA()`.
- Khi `doA` được gọi, nó in ra `"Starting doA()"`.
- Bên trong `doA`, nó lại gọi hàm `doB` bằng cách sử dụng `doB()`.
- Lúc này, điều khiển nhảy đến hàm `doB`.
- `doB` in ra `"In doB()"`.
- Sau khi `doB` thực thi xong, điều khiển quay trở lại `doA` (hàm gọi `doB`).
- `doA` in ra `"Ending doA()"`.
- Điều khiển quay trở lại `main` (hàm gọi `doA`).
- `main` in ra `"Ending main()"`.
- Chương trình kết thúc.

**Tóm lại:**

Các hàm có thể gọi cho nhau, tạo ra các chuỗi thực thi phức tạp hơn. Bất kỳ hàm nào cũng có thể gọi bất kỳ hàm nào khác, miễn là hàm được gọi đã được định nghĩa trước đó trong chương trình.

### **C++ không hỗ trợ hàm lồng nhau**

Trái ngược với một số ngôn ngữ lập trình khác, C++ không cho phép định nghĩa hàm bên trong các hàm khác. Tính năng này được gọi là định nghĩa hàm lồng nhau. (nested function)

>```
>#include <iostream>
>
>int main() {
>    void foo() { // Dòng này bất hợp lệ trong C++
>        std::cout << "foo!\n";
>    }
>
>    foo(); // Dòng này cố gắng gọi hàm lồng nhau
>    return 0;
>}
>```

**Lỗi:** Dòng `void foo()` cố gắng định nghĩa một hàm có tên `foo` bên trong hàm `main`. Điều này không được phép trong C++.

Trong C++, các hàm cần được định nghĩa bên ngoài các hàm khác:

>```
>#include <iostream>
>
>void foo() { // Định nghĩa hàm bên ngoài main
>    std::cout << "foo!\n";
>}
>
>int main() {
>    foo(); // Gọi hàm foo
>    return 0;
>}
>```

>**Thông tin bổ sung:** <br>
>Biến siêu cú pháp: Mã sử dụng `"foo"` làm tên giữ chỗ cho hàm. Những tên giữ chỗ này thường được sử dụng khi tên cụ thể không quan trọng để minh họa một khái niệm.<br>
Các ví dụ phổ biến khác bao gồm `"bar"`, `"baz"` hoặc các từ 3 chữ cái kết thúc bằng `"oo"` (`goo`, `moo`, `boo`).
