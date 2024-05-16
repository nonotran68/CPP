## **Bài 2.x: <u>Tổng kết và bài kiểm tra</u>**

### **Tóm tắt bài học - Về các hàm trong C++**

Bài học này giới thiệu những kiến thức cơ bản về hàm trong C++. Dưới đây là các điểm chính:

- **Hàm:** Khối mã có thể tái sử dụng được thiết kế để thực hiện một nhiệm vụ cụ thể. Bạn có thể tự định nghĩa hàm (hàm do người dùng định nghĩa) hoặc sử dụng hàm được tích hợp sẵn.

- **Gọi hàm:** Câu lệnh hướng dẫn chương trình thực thi một hàm. Hàm gọi hàm khác được gọi là hàm gọi, và hàm bị gọi được gọi là hàm bị gọi hoặc hàm được gọi (LMAO). Hãy nhớ sử dụng dấu ngoặc đơn khi gọi hàm.

- **Thân hàm:** Mã nằm trong dấu ngoặc nhọn, định nghĩa chức năng của hàm.

- **Hàm trả về giá trị:** Hàm trả về giá trị cho hàm gọi. Kiểu trả về chỉ định kiểu dữ liệu của giá trị trả về. Câu lệnh `return` xác định giá trị cụ thể được gửi lại. Quá trình này được gọi là **"trả về theo giá trị."**

- **Giá trị trả về của hàm `main()`:** Một trường hợp đặc biệt gọi là **mã trạng thái** (**status code**), thông báo cho hệ điều hành liệu chương trình có chạy thành công (thường là 0) hay không (khác 0).

- **Lập trình DRY:** Tránh các mã trùng lặp bằng cách sử dụng hàm và biến.

- **Hàm `void`:** Hàm không trả về giá trị nào cho hàm gọi. Chúng hữu ích để thực hiện các hành động mà không cần giá trị trả về.

- **Trả về sớm:** Câu lệnh `return` thoát khỏi hàm trước khi đến cuối hàm.

- **Tham số hàm:** Biến trong hàm nhận giá trị từ hàm gọi. Các giá trị này được gọi là **đối số**. Quá trình này được gọi là **"truyền theo giá trị."**

- **Biến cục bộ:** Biến được định nghĩa trong thân hàm. Chúng chỉ tồn tại trong khi hàm đang chạy (thời gian chạy hay runtime) và chỉ có thể truy cập được trong phạm vi của hàm.

- **Khoảng trắng**: Ký tự định dạng như dấu cách, tab và ký tự dòng mới.

- **Tiền khai báo:** Thông báo cho trình biên dịch về sự tồn tại của một định danh trước khi định nghĩa định danh đó bằng cách sử dụng **nguyên mẫu hàm** (kiểu trả về, tên, tham số, không có thân hàm, dấu chấm phẩy).

- **Định nghĩa vs. khai báo:** Định nghĩa thực sự triển khai (đối với hàm và kiểu) hoặc khởi tạo (đối với biến) một định danh. Khai báo là câu lệnh thông báo cho trình biên dịch về sự tồn tại của định danh. Trong C++, tất cả các định nghĩa đều phục vụ như khai báo. Khai báo thuần túy là những khai báo không phải là định nghĩa (như nguyên mẫu hàm).

- **Đa tệp:** Các chương trình lớn hơn thường được chia thành nhiều tệp nguồn.

- **Xung đột đặt tên:** Khi hai định danh có cùng tên, trình biên dịch hoặc trình liên kết không thể phân biệt được chúng và sẽ báo lỗi. Không gian tên giúp đảm bảo các định danh duy nhất trong phạm vi cụ thể (ví dụ: không gian tên `std`).

- **Bộ tiền xử lý:** Chương trình xử lý mã trước khi biên dịch. Nó xử lý các chỉ thị (hướng dẫn đặc biệt bắt đầu bằng `#`) và `macro` (quy tắc thay thế văn bản).

- **Tệp tiêu đề:** Tệp chứa các khai báo để các tệp mã khác sử dụng. Chỉ thị `#include` thay thế chính nó bằng nội dung của tệp được chèn. Sử dụng dấu ngoặc góc `<>` cho tiêu đề hệ thống và dấu ngoặc kép `""` cho tiêu đề do người dùng định nghĩa. Chèn tệp tiêu đề hệ thống mà không có phần mở rộng *.h* nếu chúng có sẵn.

- **Bộ bảo vệ tiêu đề (header guard)**: Ngăn tệp tiêu đề bị chép nhiều lần trong cùng một tệp mã.
