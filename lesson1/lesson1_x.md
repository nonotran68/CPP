## **Bài 1.x: <u>Tổng kết và bài kiểm tra</u>**

### **Tóm tắt:**


**Câu lệnh (statement):** Là một dạng hướng dẫn chương trình thực hiện một hành động nào đó. Thường kết thúc bằng dấu chấm phẩy (`;`).

**Hàm (function):** Là một tập hợp các câu lệnh được thực thi tuần tự. Mỗi chương trình C++ phải bao gồm một hàm đặc biệt tên là `main`. Khi bạn chạy chương trình, việc thực thi bắt đầu từ đầu hàm `main`.

**Định danh (identifier):** Trong lập trình, tên của hàm (hoặc đối tượng, kiểu dữ liệu, mẫu template, v.v.) được gọi là định danh của nó.

**Cú pháp (syntax):** Là các quy tắc chi phối cách xây dựng các thành phần của ngôn ngữ C++. **Lỗi cú pháp (syntax error)** xảy ra khi bạn vi phạm các quy tắc ngữ pháp của ngôn ngữ.

**Chú thích (comment):** Cho phép lập trình viên để lại ghi chú trong code. C++ hỗ trợ hai loại chú thích:
Chú thích dòng bắt đầu bằng `//` và kéo dài đến hết dòng.
Chú thích khối bắt đầu bằng `/*` và kết thúc bằng `*/`. Không nên lồng các chú thích khối.
Bạn có thể sử dụng chú thích để tạm thời vô hiệu hóa các dòng hoặc phần code. Đây được gọi là đóng chú thích đoạn code `(commenting out your code)`.

**Dữ liệu (data):** Là bất kỳ thông tin nào có thể được di chuyển, xử lý hoặc lưu trữ bởi máy tính. Một đơn vị dữ liệu riêng lẻ được gọi là giá trị (value). Các ví dụ phổ biến về giá trị bao gồm chữ cái (ví dụ: `a`), số (ví dụ: `5`) và văn bản (ví dụ: `Xin chào`).

**Biến (variable):** Là một vùng nhớ được đặt tên mà chúng ta có thể sử dụng để lưu trữ giá trị. Để tạo biến, chúng ta sử dụng một câu lệnh gọi là **câu lệnh khai báo (definition statement).** Khi chương trình chạy, mỗi biến được khai báo sẽ được khởi tạo (instantiated), nghĩa là nó được gán một địa chỉ nhớ.

**Kiểu dữ liệu (data type):** Cho biết với trình biên dịch (compiler) cách diễn giải một phần dữ liệu thành giá trị có ý nghĩa. **Một số nguyên (integer)** là một số có thể được viết mà không có phần thập phân, chẳng hạn như `4`, `27`, `0`, `-2` hoặc `-12`.

**Gán sao chép (copy assignment)** (thông qua toán tử `=`) có thể được sử dụng để gán giá trị cho một biến đã được tạo.

**Khởi tạo (initialization):** Quá trình chỉ định giá trị ban đầu cho một đối tượng được gọi là khởi tạo, và cú pháp được sử dụng để khởi tạo một đối tượng được gọi là bộ khởi tạo (initializer).

Nói một cách đơn giản, C++ hỗ trợ 6 loại khởi tạo cơ bản:

| **Loại khởi tạo**            | **Ví dụ**        | **Ghi chú**                                                      |
|------------------------------|------------------|------------------------------------------------------------------|
| Khởi tạo mặc định            | `int x;`         | Trong hầu hết các trường hợp, để biến với giá trị không xác định |
| Khởi tạo sao chép            | `int x = 5;`     |                                                                  |
| Khởi tạo trực tiếp           | `int x ( 5 );`   | Đôi khi được gọi là khởi tạo bằng dấu ngoặc đơn                  |
| Khởi tạo danh sách trực tiếp | `int x { 5 };`   | Không được phép ép kiểu hẹp (narrow conversion)                  |
| Khởi tạo danh sách sao chép  | `int x = { 5 };` | Không được phép ép kiểu hẹp                                      |
| Khởi tạo giá trị             | `int x {};`      | Thường thực hiện khởi tạo bằng 0                                 |

Khởi tạo trực tiếp đôi khi được gọi là khởi tạo bằng dấu ngoặc đơn, và khởi tạo danh sách (bao gồm khởi tạo giá trị) đôi khi được gọi là khởi tạo đồng nhất (uniform initialization) hoặc khởi tạo bằng dấu ngoặc nhọn (brace initialization).
Bạn nên ưu tiên khởi tạo bằng dấu ngoặc nhọn so với các dạng khởi tạo khác và ưu tiên khởi tạo so với gán.

Mặc dù bạn có thể định nghĩa nhiều biến trong một câu lệnh duy nhất, nhưng tốt hơn là nên định nghĩa và khởi tạo từng biến trên một dòng riêng, trong một câu lệnh riêng biệt.

`std::cout` và toán tử `<<` cho phép chúng ta xuất kết quả của một biểu thức ra bảng điều khiển (console).

`std::endl` xuất ra một ký tự xuống dòng, buộc con trỏ nhấp nháy của bảng điều khiển di chuyển đến dòng tiếp theo và xả bất kỳ đầu ra nào đang chờ xử lý ra bảng điều khiển. Ký tự `'\n'` cũng xuất ra một ký tự xuống dòng, nhưng cho phép hệ thống quyết định thời điểm xả đầu ra. Hãy cẩn thận không sử dụng `'/n'` (gạch chéo hướng về trước).

`std::cin` và toán tử `>>` cho phép chúng ta lấy giá trị từ bàn phím.

Một biến chưa được gán giá trị được gọi là biến chưa được khởi tạo. Việc cố gắng lấy giá trị của một biến chưa được khởi tạo sẽ dẫn đến **trạng thái bất định (undefined behavior)**, có thể biểu hiện theo nhiều cách khác nhau.

C++ dành riêng một bộ tên gọi là **từ khóa (keyword)**. Chúng có ý nghĩa đặc biệt trong ngôn ngữ và không được sử dụng làm tên biến.

Một giá trị nguyên văn (literal constant) là một giá trị cố định được đưa trực tiếp vào mã nguồn. Ví dụ như `5` và `"Hello world!"`.

**Một phép toán (operation)** là một quá trình liên quan đến không hoặc nhiều giá trị đầu vào, được gọi là **toán hạng (operand)**. Phép toán cụ thể cần thực hiện được biểu thị bằng **toán tử (operator)** được cung cấp. Kết quả của một phép toán tạo ra một **giá trị đầu ra**.

**Toán tử một ngôi (Unary operator)** lấy một toán hạng.
**Toán tử hai ngôi (Binary operator)** lấy hai toán hạng, thường được gọi là trái và phải.
**Toán tử ba ngôi (Ternary operator)** lấy ba toán hạng.
**Toán tử không ngôi (Nullary operator)** lấy không toán hạng.

**Một biểu thức (expression)** là một chuỗi các literal, biến, toán tử và lời gọi hàm được tính toán để tạo ra một giá trị đầu ra duy nhất. Việc tính toán giá trị đầu ra này được gọi là **đánh giá (evaluation).** Giá trị được tạo ra là **kết quả (result)** của biểu thức.

**Một câu lệnh biểu thức (expression statement)** là một biểu thức được chuyển thành một câu lệnh bằng cách đặt dấu chấm phẩy ở cuối biểu thức.

Khi viết chương trình, hãy thêm một vài dòng hoặc một hàm, biên dịch, giải quyết bất kỳ lỗi nào và đảm bảo nó hoạt động. Đừng đợi cho đến khi bạn viết toàn bộ chương trình mới biên dịch nó lần đầu tiên!

Tập trung vào việc làm cho mã của bạn hoạt động. Sau khi bạn chắc chắn sẽ giữ lại một phần mã nào đó, thì bạn có thể dành thời gian để loại bỏ (hoặc đóng chú thích) mã tạm thời/gỡ lỗi, thêm chú thích, xử lý các trường hợp lỗi, định dạng mã của bạn, đảm bảo tuân theo các quy trình thực hành tốt nhất, loại bỏ logic trùng lặp, v.v.

Các chương trình bản nháp đầu tiên thường lộn xộn và không hoàn hảo. Hầu hết các code cần được dọn dẹp và tinh chỉnh để trở nên tuyệt vời!
