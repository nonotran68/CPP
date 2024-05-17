```python

```

## **Bài 3.x: <u>Tổng kết và Bài tập</u>** 

### **Tổng quan chương**

- **Lỗi cú pháp (syntax error):** Là lỗi xảy ra khi bạn viết một câu lệnh không hợp lệ theo ngữ pháp của ngôn ngữ C++. Trình biên dịch sẽ phát hiện ra những lỗi này.
- **Lỗi ngữ nghĩa (semantic error):** Là lỗi xảy ra khi một câu lệnh tuy hợp ngữ pháp nhưng không thực hiện được như ý định của lập trình viên.
- **Gỡ lỗi (debugging):** Là quá trình tìm và loại bỏ lỗi ra khỏi chương trình.
- **Quy trình gỡ lỗi gồm 5 bước:**
    - Tìm nguyên nhân gốc.
    - Hiểu rõ vấn đề.
    - Xác định cách sửa chữa.
    - Sửa chữa vấn đề.
    - Kiểm tra lại.

- Thường thì việc tìm ra lỗi là bước khó nhất trong quá trình gỡ lỗi.

- **Công cụ phân tích tĩnh (static analysis tool):** Là các công cụ phân tích code của bạn và tìm kiếm các vấn đề ngữ nghĩa có thể cho thấy trục trặc trong code.

- Để gỡ lỗi hiệu quả, bước đầu tiên và quan trọng nhất là phải tái tạo lại được lỗi một cách đáng tin cậy.

- **Một số chiến thuật giúp tìm lỗi:**
    - Chú thích code (commenting out code).
    - Sử dụng các câu lệnh xuất ra màn hình (output statements) để xác nhận luồng code.
    - In ra giá trị các biến (printing values).

- Khi sử dụng các câu lệnh in để gỡ lỗi, nên dùng std::cerr thay vì std::cout. Tuy nhiên, cách tốt nhất là tránh gỡ lỗi hoàn toàn bằng cách in ra màn hình.

- **Tệp nhật ký (log file):** Là một tệp tin ghi lại các sự kiện xảy ra trong chương trình. Quá trình ghi thông tin vào tệp nhật ký được gọi là **ghi nhật ký (logging).**

- **Tái cấu trúc (refactoring):** Là quá trình sắp xếp lại code mà không làm thay đổi chức năng của nó. Thường được thực hiện để làm cho chương trình được tổ chức tốt hơn, mô đun hơn hoặc hoạt động hiệu quả hơn.

- **Kiểm thử đơn vị (unit testing):** Là một phương pháp kiểm thử phần mềm theo đó các đơn vị nhỏ của mã nguồn được kiểm thử để xác định xem chúng có chính xác hay không.
- **Lập trình phòng thủ (defensive programming):** Là một kỹ thuật mà lập trình viên cố gắng dự đoán tất cả các cách phần mềm có thể bị sử dụng sai. Những cách sử dụng sai này thường có thể được phát hiện và giảm thiểu.
- **Trạng thái chương trình (program state):** Là tất cả thông tin được theo dõi trong một chương trình (giá trị biến, các hàm đã được gọi, điểm thực thi hiện tại).
- **Bộ gỡ lỗi (debugger):** Là một công cụ cho phép lập trình viên kiểm soát cách chương trình thực thi và kiểm tra trạng thái chương trình trong khi chương trình đang chạy.
- **Bộ gỡ lỗi tích hợp (integrated debugger):** Là một bộ gỡ lỗi tích hợp vào trình soạn thảo code.
- **Kiểm tra từng bước (stepping):** Là tên gọi chung cho một tập hợp các tính năng gỡ lỗi liên quan cho phép bạn từng bước đi qua code theo từng câu lệnh.
    - **Nhảy vào (step into):** Thực thi câu lệnh tiếp theo trong đường dẫn thực thi thông thường của chương trình, sau đó tạm dừng thực thi. Nếu câu lệnh chứa một lời gọi hàm, **step into** sẽ khiến chương trình nhảy đến đầu hàm được gọi.
    - **Nhảy qua (step over):** Thực thi câu lệnh tiếp theo trong đường dẫn thực thi thông thường của chương trình, sau đó tạm dừng thực thi. Nếu câu lệnh chứa một lời gọi hàm, **step over** sẽ thực thi hàm đó và trả quyền điều khiển cho bạn sau khi hàm đã được thực thi.

    - **Thoát ra (step out):** Thực thi tất cả mã còn lại trong hàm đang được thực thi và sau đó trả quyền điều khiển cho bạn khi hàm đã trả về.
- **Chạy đến con trỏ chuột (run to cursor):** Thực thi chương trình cho đến khi thực thi đạt đến câu lệnh được chọn bởi con trỏ chuột của bạn.
- **Tiếp tục (continue):** Chạy chương trình, cho đến khi chương trình kết thúc hoặc gặp **điểm dừng (breakpoint)**. **Bắt đầu (start)** giống như **Continue**, chỉ khác là bắt đầu từ đầu chương trình.
- **Điểm dừng (breakpoint):** Là một đánh dấu đặc biệt trong code, thông báo cho bộ gỡ lỗi tạm dừng thực thi chương trình khi chạy đến điểm dừng này.
- **Thiết lập câu lệnh tiếp theo (set next statement):** Lệnh này cho phép bạn thay đổi điểm thực thi sang một câu lệnh khác (đôi khi được gọi không chính thức là "nhảy"). Tính năng này có thể được sử dụng để:
  - Nhảy đến một câu lệnh phía trước và bỏ qua một số đoạn code lẽ ra sẽ được thực thi.
  - Nhảy ngược lại và thực thi lại một đoạn code đã được thực thi trước đó.
- **Theo dõi biến (watching a variable):** Cho phép bạn kiểm tra giá trị của một biến trong khi chương trình đang chạy ở chế độ gỡ lỗi. **Cửa sổ theo dõi (watch window):** Là cửa sổ trong bộ gỡ lỗi hiển thị giá trị của các biến hoặc biểu thức.
- **Ngăn xếp lệnh gọi (call stack):** Là danh sách tất cả các hàm đang hoạt động đã được thực thi để đến được điểm thực thi hiện tại. **Cửa sổ ngăn xếp lệnh gọi (call stack window):** Là cửa sổ trong bộ gỡ lỗi hiển thị ngăn xếp gọi.

### **Bài tập**

#### **Câu hỏi #1:**

Chương trình sau đây được thiết kế để cộng hai số, nhưng không hoạt động chính xác. Sử dụng bộ gỡ lỗi tích hợp để kiểm tra từng bước thực thi chương trình này và theo dõi giá trị của `x`. Dựa trên thông tin bạn tìm được, hãy sửa lỗi cho chương trình sau:
>```
>#include <iostream>
>
>int readNumber(int x) {
>  std::cout << "Please enter a number: ";
>  std::cin >> x;
>  return x;
>}
>
>void writeAnswer(int x) {
>  std::cout << "The sum is: " << x << '\n';
>}
>
>int main() {
>  int x {};
>  readNumber(x);
>  x = x + readNumber(x);
>  writeAnswer(x);
>
>  return 0;
>}
>```

#### ****Gợi ý giải:****

Vấn đề nằm ở dòng `x = x + readNumber(x)`. Hàm `readNumber` yêu cầu nhập giá trị nhưng không gán giá trị trả về cho `x` bên trong hàm `main`. Do đó, `readNumber(x)` được gọi lần thứ hai sẽ không ghi đè lên giá trị cũ của `x` mà cộng với giá trị cũ, dẫn đến kết quả sai.

**Sửa chữa:**
>```
>x = x + readNumber();  // Gọi readNumber() mà không truyền tham số x
>```

#### **Câu hỏi #2** 

Chương trình sau đây được thiết kế để chia hai số nhưng không hoạt động chính xác. Sử dụng bộ gỡ lỗi tích hợp để từng bước thực thi chương trình. Với đầu vào là 8 và 4. Dựa trên thông tin bạn tìm được, hãy sửa lỗi cho chương trình sau:
>```
>#include <iostream>
>
>int readNumber() {
>  std::cout << "Please enter a number: ";
>  int x {};
>  std::cin >> x;
>  return x;
>}
>
>void writeAnswer(int x) {
>  std::cout << "The quotient is: " << x << '\n';
>}
>
>int main() {
>  int x {};
>  int y {};
>  x = readNumber();
>  x = readNumber();
>  writeAnswer(x / y);
>
>  return 0;
>}
>```

#### **Gợi ý giải:**

Vấn đề nằm ở dòng `writeAnswer(x / y)`. Biến `y` chưa được gán giá trị trước khi sử dụng trong phép chia. Chia cho một biến chưa được khởi tạo thường dẫn đến lỗi.

**Sửa chữa:**
>```
>y = readNumber();  // Đọc giá trị cho y trước khi thực hiện phép chia
>writeAnswer(x / y);
>```

#### **Câu hỏi #3:**

Ngăn xếp gọi trông như thế nào trong chương trình sau khi thực thi đến dòng `4`? Chỉ cần cung cấp tên hàm, không cần số dòng biểu thị điểm trả về.
>```
>#include <iostream>
>
>void d() { // here }
>
>void c() {
>}
>
>void b() {
>  c();
>  d();
>}
>
>void a() {
>  b();
>}
>
>int main() {
>  a();
>
>  return 0;
>}
>```

#### **Trả lời:**

Ngăn xếp gọi khi thực thi đến dòng `4` sẽ là:
>```
>d  // Hàm hiện tại đang được thực thi
>b  // Hàm b gọi hàm c và d
>a  // Hàm a gọi hàm b
>main  // Hàm main gọi hàm a
>```

Ngăn xếp gọi lưu trữ các hàm đang hoạt động theo thứ tự gọi, với hàm được gọi gần nhất nằm ở trên cùng.
