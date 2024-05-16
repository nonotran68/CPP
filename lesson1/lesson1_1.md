## **Bài 1.1: <u>Lệnh và cấu trúc của một chương trình C++</u>**

### **Câu lệnh**

- Một chương trình máy tính là 1 chuỗi các chỉ dẫn (instructions) để máy tính thực hiện. Câu lệnh là một loại chỉ dẫn khiến máy tính thực hiện hành động nào đó. Câu lệnh là đơn vị nhỏ nhất trong 1 cấu trúc chương trình C++.
- Hầu hết (nhưng không phải tất cả) các câu lệnh C++ đều kết thúc bằng dấu `;`
- Vì C++ là 1 ngôn ngữ bậc cao nên 1 câu lệnh có thể dịch thành nhiều lệnh mã máy.
> Có nhiều loại câu lệnh trong C++, bao gồm:
> - Câu lệnh điều khiển:
>   - `if`, `else`, `switch`: Dùng để điều khiển luồng thực thi của chương trình dựa trên điều kiện.
>   - `for`, `while`, `do while`: Dùng để lặp lại một khối mã nhiều lần.
>   - `break`, `continue`: Dùng để điều khiển việc lặp lại trong các vòng lặp.
> - Câu lệnh gán:
>   - `=`: Dùng để gán giá trị cho biến.
> - Câu lệnh nhập xuất:
>   - `cin`, `cout`: Dùng để nhập dữ liệu từ bàn phím và xuất dữ liệu ra màn hình.
>   - `cin.get()`, `cout.put()`: Dùng để nhập xuất từng ký tự một.
> - Câu lệnh toán học:
>   - Các phép toán cộng, trừ, nhân, chia, modulo (`+, -, *, /, %`).
>   - Các phép toán toán học nâng cao như `log, exp, sqrt, pow`.
> - Câu lệnh logic:
>   - `&&`, `||`, `!`: Dùng để thực hiện các phép toán logic AND, OR, NOT.
> - Câu lệnh khai báo:
>   - `int`, `float`, `char`, `string`: Dùng để khai báo biến với các kiểu dữ liệu khác nhau.
>   - `const`, `volatile`: Dùng để khai báo các thuộc tính của biến.
> - Câu lệnh khác:
>   - `return`: Dùng để trả về giá trị từ hàm.
>   - `goto`: Dùng để chuyển đến một nhãn cụ thể trong chương trình.
>   -  Vân vân..........

### **Hàm và hàm main()**

- Trong C++, các câu lệnh thường được nhóm lại thành các đơn vị được gọi là các hàm. **Hàm** là 1 tập hợp các lệnh thực thi tuần tự (từ trên xuống).
> ***Quy tắc***:
> - Hàm `main()` là điểm bắt đầu của mọi chương trình C++. Hàm này được thực thi đầu tiên khi chương trình khởi chạy.
> - Hàm `main()` bắt buộc phải có trong mọi chương trình C++.
> - Các chương trình thường kết thúc (chạy xong) sau khi câu lệnh cuối cùng bên trong hàm `main()` được thực thi (mặc dù các chương trình có thể bị hủy sớm trong một số trường hợp hoặc thực hiện một số thao tác dọn dẹp sau đó).
- Các hàm thường được viết để thực hiện một công việc cụ thể. Ví dụ: một hàm có tên `max` có thể chứa các câu lệnh tìm ra số nào lớn hơn trong hai số. Hàm có tên là `CalculateGrade` có thể tính điểm của học sinh từ một tập hợp điểm kiểm tra. Một hàm có tên `printEmployee` có thể in thông tin của nhân viên ra bảng điều khiển. Chúng ta sẽ sớm nói nhiều hơn về các hàm vì chúng là công cụ tổ chức được sử dụng phổ biến nhất trong một chương trình.
> ***Thuật ngữ***
> - Khi thảo luận về hàm, cách viết tắt khá phổ biến là thêm một cặp dấu ngoặc đơn vào cuối tên hàm. Ví dụ: nếu bạn thấy thuật ngữ `main()` hoặc `doSomething()`, thì đây là cách viết tắt tương ứng của các hàm có tên `main` hoặc `doSomething`. Điều này giúp phân biệt hàm với những thứ khác bằng tên (chẳng hạn như biến) mà không cần phải viết từ “hàm” mỗi lần.


### **Phân tích chương trình *"Hello world"***

Bây giờ bạn đã hiểu ngắn gọn về câu lệnh và hàm là gì, hãy quay lại chương trình “Hello world” (xin chào thế giới) và xem xét kỹ hơn chức năng của từng dòng một cách chi tiết hơn.
```
1 #include <iostream>
2 
3 int main()
4 {
5   std::cout << "Hello world!";
6   return 0;
7 }
```
- Dòng 1 được gọi là chỉ thị tiền xử lí (preprocessor directive). Lệnh tiền xử lý này cho biết rằng chúng ta muốn sử dụng nội dung của thư viện `iostream`, một phần của thư viện chuẩn C++ cho phép chúng ta đọc và ghi văn bản từ/đến bảng điều khiển. Chúng ta cần dòng này để sử dụng `std::cout` trên dòng 5. Việc loại trừ dòng này sẽ dẫn đến lỗi biên dịch trên dòng 5, vì trình biên dịch sẽ không biết `std::cout` là gì.
- Dòng 2 trống và bị trình biên dịch bỏ qua. Dòng này chỉ tồn tại để giúp con người dễ đọc chương trình hơn (bằng cách tách chỉ thị tiền xử lý `#include` và các phần tiếp theo của chương trình).
- Dòng 3 cho trình biên dịch biết rằng chúng ta sẽ viết (định nghĩa) một hàm có tên (mã định danh) là `main`. Như bạn đã học ở trên, mọi chương trình C++ đều phải có một hàm `main` nếu không sẽ không liên kết được.
- Dòng 4 và 7 cho trình biên dịch biết dòng nào là một phần của hàm `main`. Tất cả mọi thứ nằm giữa ngoặc nhọn mở ở dòng 4 và ngoặc nhọn đóng ở dòng 7 được coi là một phần của thân hàm `main`. Đây được gọi là thân hàm.
- Dòng 5 là câu lệnh đầu tiên trong hàm `main` và là câu lệnh đầu tiên được thực thi khi chúng tôi chạy chương trình. `std::cout` (viết tắt của “character output”) và toán tử << cho phép chúng tôi hiển thị thông tin trên bảng điều khiển. Trong trường hợp này, chúng tôi đang hiển thị văn bản "Hello world!". Câu lệnh này tạo ra đầu ra hiển thị của chương trình.
- Dòng 6 là một câu lệnh return. Khi một chương trình thực thi được kết thúc, chương trình sẽ gửi một giá trị trở lại hệ điều hành để cho biết nó có chạy thành công hay không. Câu lệnh return cụ thể này trả về giá trị 0 cho hệ điều hành, có nghĩa là “mọi thứ đều ổn!”. Đây là câu lệnh cuối cùng trong chương trình được thực thi.

Tất cả các chương trình chúng tôi viết sẽ tuân theo khuôn mẫu chung này hoặc biến thể của nó.

Bạn có thể tự mình biên dịch và chạy chương trình này và bạn sẽ thấy nó xuất ra bảng điều khiển những thông tin sau:
> `Hello world!`




### **Cú pháp và lỗi cú pháp**

- **Cú pháp** là tập hợp các quy tắc chi phối cách viết mã C++ hợp lệ. Nó bao gồm các quy tắc về:
  - **Từ khóa**: Các từ khóa được sử dụng để xác định các cấu trúc ngôn ngữ như hàm, vòng lặp và điều kiện.
  - **Định danh**: Định danh là tên được sử dụng cho các biến, hàm và các thực thể khác trong chương trình.
  - **Toán tử**: Toán tử được sử dụng để thực hiện các phép toán trên các toán hạng.
  - **Biểu thức**: Biểu thức là một tập hợp các toán hạng và toán tử được kết hợp để tạo ra một giá trị.
  - **Câu lệnh**: Câu lệnh là một chỉ dẫn cho trình biên dịch thực hiện một hành động.
  - **Cấu trúc**: Cấu trúc là một cách để nhóm các câu lệnh lại với nhau.
- **Lỗi cú pháp** là lỗi xảy ra khi mã C++ vi phạm các quy tắc cú pháp. Lỗi cú pháp sẽ khiến trình biên dịch không thể biên dịch mã.
- Một số ví dụ về lỗi cú pháp:
    - Sai chính tả từ khóa.
    - Thiếu dấu chấm phẩy ở cuối câu lệnh.
    - Sai số lượng ngoặc đơn hoặc ngoặc nhọn.
    - Sử dụng định danh không hợp lệ.
- Cách khắc phục lỗi cú pháp:
    - Đọc kỹ thông báo lỗi của trình biên dịch.
    - Kiểm tra mã của bạn để tìm các lỗi chính tả và lỗi đánh máy.
    - Tham khảo tài liệu về cú pháp C++ để đảm bảo rằng bạn đang sử dụng các quy tắc cú pháp chính xác.
- Để tránh lỗi cú pháp:
    - Sử dụng trình soạn thảo mã có hỗ trợ tô sáng cú pháp (syntax highlighting).
    - Kiểm tra mã của bạn cẩn thận trước khi biên dịch.
    - Viết mã theo từng bước nhỏ và kiểm tra từng bước.

Hãy xem điều gì sẽ xảy ra nếu chúng ta bỏ qua dấu chấm phẩy ở dòng 5 của chương trình “Hello world”, như sau:
```
#include <iostream>

int main()
{
   std::cout << "Hello world!"
   return 0;
}
```
Trình biên dịch sẽ báo lỗi cho chúng ta biết: 
```
ls1.cpp: In function ‘int main()’:
ls1.cpp:3:32: error: expected ‘;’ before ‘return’
    3 |     std::cout << "Hello world!"
      |                                ^
      |                                ;
    4 |     return 0;
      |     ~~~~~~                      
```
