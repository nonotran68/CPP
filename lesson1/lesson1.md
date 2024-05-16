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

## **Bài 1.2: <u>Chú thích</u>**

- Chú thích là những dòng văn bản được thêm vào mã C++ để giúp con người hiểu rõ hơn về mã. Chúng bị trình biên dịch bỏ qua và không ảnh hưởng đến cách chương trình chạy.
- Trong C++ có hai kiểu chú thích khác nhau, cả hai đều phục vụ cùng một mục đích: giúp các lập trình viên ghi lại mã theo một cách nào đó.
    - **Chú thích một dòng**: Bắt đầu bằng `//` và kết thúc ở cuối dòng.
    > <u>Ví dụ:</u>
    > 
    > `std::cout << "Hello world!"; // Everything from here to the end of the line is ignored`
    - **Chú thích nhiều dòng**: Bắt đầu bằng `/*` và kết thúc bằng `*/`.
    > <u>Ví dụ:</u>
    > 
    > `/* Đây là chú thích nhiều dòng`\
    > `Có thể bao gồm nhiều dòng */`
- Chú thích có thể được sử dụng để:
    - Giải thích mục đích của một đoạn mã.
    - Ghi chú về cách thức hoạt động của một đoạn mã.
    - Ghi chú về các thay đổi đã được thực hiện đối với mã.
    - Ghi chú về các vấn đề tiềm ẩn với mã.
- Dưới đây là một số mẹo để sử dụng chú thích hiệu quả:
    - Viết chú thích rõ ràng và súc tích.
    - Sử dụng chú thích để giải thích những phần mã phức tạp.
    - Sử dụng chú thích để ghi chú về các thay đổi quan trọng đối với mã.
    - Sử dụng chú thích để ghi chú về các vấn đề tiềm ẩn với mã.
    - Tránh sử dụng chú thích để lặp lại thông tin hiển nhiên trong mã.

- Ví dụ về chú thích tốt:
  - Giải thích mục đích của đoạn mã:
  ```
    // Hàm này tính diện tích của một hình vuông
    int square_area(int side_length) {
      return side_length * side_length;
    }
  ```
  - Ghi chú về cách thức hoạt động của một đoạn mã:
  ```
    // Vòng lặp này in ra các số từ 1 đến 10
    for (int i = 1; i <= 10; i++) {
      std::cout << i << std::endl;
    }

  ```
  - Ghi chú về các thay đổi đã được thực hiện đối với mã:
  ```
    // Đã sửa lỗi trong hàm `square_area`
    // Hàm hiện hoạt động chính xác cho tất cả các giá trị đầu vào
  ```
  - Ghi chú về các vấn đề tiềm ẩn với mã:
  ```
    // Lưu ý: Hàm này có thể gây tràn bộ nhớ nếu `n` quá lớn
    int factorial(int n) {
      if (n == 0) {
        return 1;
      } else {
        return n * factorial(n - 1);
      }
    }

  ```
- Chú thích tệ:
    - Lặp lại thông tin hiển nhiên trong mã:
    ```
        // int i = 1; // Biến i được khởi tạo với giá trị 1

    ```
    - Chú thích không rõ ràng:
    ```
    // Hàm này thực hiện một số phép toán
        int do_something(int a, int b) {
          // ...
        }
    ```
    - Chú thích không hữu ích:
    ```
        // Đây là một hàm
        void my_function() {
          // ...
        }
    ```
- **Chú thích tốt giúp cho mã C++ của bạn dễ đọc và dễ hiểu hơn.**


## **Bài 1.3: <u>Đối tượng và biến trong C++</u>**

### **Dữ liệu và biến**
- Ta đã biết rằng phần lớn các chỉ dẫn trong một chương trình là các câu lệnh và hàm là nhóm các câu lệnh thực thi tuần tự. Các câu lệnh bên trong hàm thực hiện các hành động (hy vọng) tạo ra bất kỳ kết quả nào mà chương trình được thiết kế để tạo ra.
- Nhưng làm thế nào để các chương trình thực sự tạo ra kết quả? Họ làm như vậy bằng cách thao tác (đọc, thay đổi và ghi) dữ liệu. Trong điện toán, dữ liệu là bất kỳ thông tin nào có thể được di chuyển, xử lý hoặc lưu trữ bởi máy tính.
> **Chú ý quan trọng:**\
> Chương trình là tập các chỉ dẫn thao tác với dữ liệu để tạo ra kết quả mong muốn.


- Chương trình có thể lấy dữ liệu để xử lý theo nhiều cách khác nhau: từ file hoặc cơ sở dữ liệu, qua mạng, từ người dùng nhập liệu trên bàn phím, hoặc từ chính lập trình viên đưa dữ liệu trực tiếp vào mã nguồn của chương trình. Trong chương trình "Hello World" từ bài học đã đề cập, văn bản "Hello World!" được chèn trực tiếp vào mã nguồn của chương trình, cung cấp dữ liệu cho chương trình sử dụng. Sau đó, chương trình thao tác với dữ liệu này bằng cách gửi nó đến màn hình để hiển thị.
- Dữ liệu trên máy tính thường được lưu trữ ở định dạng hiệu quả cho việc lưu trữ hoặc xử lý (và do đó không thể đọc được bằng con người). Vì vậy, khi chương trình "Hello World" được biên dịch, văn bản "Hello World!" được chuyển đổi thành định dạng hiệu quả hơn để chương trình sử dụng (dạng nhị phân, chúng ta sẽ thảo luận trong bài học sau).


### **Bộ nhớ truy cập ngẫu nhiên (RAM)**

- Bộ nhớ chính trong máy tính được gọi là Bộ nhớ truy cập ngẫu nhiên (thường được gọi tắt là RAM). Khi chúng ta chạy một chương trình, hệ điều hành sẽ nạp chương trình đó vào RAM. Bất kỳ dữ liệu nào được mã hóa cứng vào chính chương trình (ví dụ: văn bản như "Hello, world!") đều được nạp vào thời điểm này.
- Hệ điều hành cũng dành một phần RAM bổ sung để chương trình sử dụng trong khi chạy. Các cách sử dụng thông thường cho bộ nhớ này là lưu trữ các giá trị do người dùng nhập vào, lưu trữ dữ liệu đọc từ tệp hoặc mạng, hoặc lưu trữ các giá trị được tính toán trong khi chương trình chạy (ví dụ: tổng của hai giá trị) để có thể sử dụng lại sau.
- Bạn có thể hình dung RAM như một dãy các ô được đánh số có thể được sử dụng để lưu trữ dữ liệu trong khi chương trình đang chạy. Ở một số ngôn ngữ lập trình cũ hơn (như Applesoft BASIC), bạn có thể truy cập trực tiếp vào các ô này (ví dụ: bạn có thể viết một lệnh để "lấy giá trị được lưu trữ trong hộp thư số 7532").

### **Đối tượng và biến:**


- Trong C++, việc truy cập trực tiếp vào bộ nhớ được hạn chế. Thay vào đó, chúng ta truy cập bộ nhớ gián tiếp thông qua một đối tượng. **Đối tượng** là một vùng lưu trữ (thường là bộ nhớ) có thể chứa một giá trị và có các thuộc tính liên quan khác (chúng ta sẽ đề cập đến chúng trong các bài học sau). Cách thức trình biên dịch và hệ điều hành phân bổ bộ nhớ cho các đối tượng vượt ra ngoài phạm vi của bài học này. Nhưng điểm mấu chốt ở đây là thay vì nói "lấy giá trị được lưu trữ trong hộp thư số 7532", chúng ta có thể nói "lấy giá trị được lưu trữ bởi đối tượng này". Điều này có nghĩa là chúng ta có thể tập trung vào việc sử dụng các đối tượng để lưu trữ và truy xuất các giá trị, và không cần phải lo lắng về việc các đối tượng đó thực sự được đặt ở đâu trong bộ nhớ.

- Mặc dù các đối tượng trong C++ có thể không được đặt tên (vô danh), nhưng thông thường chúng ta đặt tên cho các đối tượng của mình bằng một **định danh**. Một đối tượng có tên được gọi là **biến**.

> **Điểm cần chú ý**:
> - Đối tượng: Là nơi lưu trữ giá trị trong bộ nhớ. Tưởng tượng như một chiếc hộp để cất giữ dữ liệu.
> - Biến: Là một đối tượng có tên (định danh). Bằng cách đặt tên cho đối tượng, bạn tạo ra cách để dễ dàng tham chiếu và truy cập giá trị mà nó lưu trữ trong suốt chương trình. Giống như dán nhãn cho các hộp để bạn có thể nhanh chóng tìm thấy dữ liệu cụ thể mà bạn cần sau này.

> **Thuật ngữ:**\
> Trong lập trình nói chung, thuật ngữ "đối tượng" thường đề cập đến một đối tượng không được đặt tên trong bộ nhớ, một biến hoặc một hàm. Trong C++, thuật ngữ "đối tượng" có định nghĩa hẹp hơn, không bao gồm hàm.


### **Khai báo biến**

- Để tạo một biến, chúng ta sử dụng câu lệnh khai báo:\
  `<kiểu dữ liệu> <tên biến>;`

> **VD:**\
> `int x; // define a variable named x, of type int`

- Trong giai đoạn biên dịch, khi trình biên dịch nhìn thấy dòng lệnh này, nó sẽ ghi nhận rằng chúng ta đang định nghĩa một biến, đặt tên cho nó là `x` và kiểu của nó là `int` (chúng ta sẽ tìm hiểu thêm về kiểu dữ liệu sau). Từ thời điểm đó trở đi (với một số hạn chế sẽ đề cập trong bài học sau), bất cứ khi nào trình biên dịch nhìn thấy định danh `x`, nó sẽ biết rằng chúng ta đang tham chiếu đến biến này.
- Khi chương trình chạy (gọi là runtime), biến sẽ được khởi tạo (instantiate). Khởi tạo là một từ ngữ chuyên môn có nghĩa là đối tượng sẽ được tạo và được gán một địa chỉ bộ nhớ. Biến phải được khởi tạo trước khi chúng có thể được sử dụng để lưu trữ giá trị. Ví dụ, giả sử biến `x` được khởi tạo tại vị trí bộ nhớ `140`. Bất cứ khi nào chương trình sử dụng biến `x`, nó sẽ truy cập vào giá trị tại vị trí bộ nhớ `140`. Một đối tượng được khởi tạo đôi khi được gọi là một thực thể (instance).

### **Kiểu dữ liệu**

- Bây giờ đây, chúng ta đã biết biến là một vùng lưu trữ được đặt tên, có thể chứa một giá trị dữ liệu (chính xác cách dữ liệu được lưu trữ sẽ là chủ đề của một bài học khác). Một kiểu dữ liệu (thường được gọi đơn giản là kiểu) cho trình biên dịch biết loại giá trị nào (ví dụ: số, chữ cái, văn bản, v.v.) mà biến sẽ lưu trữ.
- Trong ví dụ trên, biến `x` được gán kiểu `int`, nghĩa là biến `x` sẽ biểu diễn một giá trị nguyên. **Số nguyên** là một số có thể được viết mà không có phần thập phân, chẳng hạn như 4, 27, 0, -2 hoặc -12. Nói ngắn gọn, chúng ta có thể nói rằng `x` là một **biến nguyên**.
- Trong C++, kiểu của một biến phải được biết tại thời gian biên dịch (khi chương trình được biên dịch) và kiểu đó không thể thay đổi mà không cần biên dịch lại chương trình. Điều này có nghĩa là một biến nguyên chỉ có thể chứa các giá trị nguyên. Nếu bạn muốn lưu trữ một loại giá trị khác, bạn sẽ cần sử dụng một kiểu khác.
- Số nguyên chỉ là một trong nhiều kiểu mà C++ hỗ trợ sẵn. Để minh họa, đây là một ví dụ khác về việc định nghĩa một biến sử dụng kiểu dữ liệu `double`:

> `double width; // Định nghĩa một biến tên width, kiểu double`
- C++ cũng cho phép bạn tạo các kiểu dữ liệu tùy chỉnh của riêng bạn. Đây là điều chúng ta sẽ thực hiện rất nhiều trong các bài học sau và là một phần tạo nên sức mạnh của C++.
- Đối với các chương đầu, chúng ta sẽ tập trung vào các biến nguyên vì chúng đơn giản về mặt khái niệm, nhưng chúng ta sẽ sớm khám phá nhiều kiểu dữ liệu khác mà C++ cung cấp (bao gồm cả `double`).

### **Khai báo nhiều biến:**


- Có thể định nghĩa nhiều biến cùng loại trong một câu lệnh bằng cách phân tách các tên bằng dấu phẩy. Hai đoạn mã sau đây thực sự giống nhau:

>```
>int a;
>int b;
>```

> `int a, b;`
- Khi khai báo nhiều biến theo cách này, có hai lỗi phổ biến mà các lập trình viên mới thường mắc phải (không nghiêm trọng vì trình biên dịch sẽ phát hiện những lỗi này và yêu cầu bạn sửa chúng):
    - Lỗi thứ nhất: Gán kiểu cho từng biến khi khai báo nhiều biến theo trình tự.
    > `int a, int b; // Sai (trình biên dịch báo lỗi)`
    - Cách sửa
    > `int a, b; //Đúng`
    - Lỗi thứ hai: Cố gắng khai báo các biến có kiểu khác nhau trong cùng một câu lệnh, điều này không được phép. Các biến có kiểu khác nhau phải được khai báo trong các câu lệnh riêng biệt.
    > `int a, double b; // Sai (trình biên dịch báo lỗi)`
    - Cách sửa 1:
    >```
    >int a; double b; // Đúng (nhưng không khuyến khích)
    >```
    - Cách sửa 2:
    >```
    >int a;
    >double b; // Đúng và được khuyến khích (dễ đọc hơn)
    >```
- Giải thích:
    - Lỗi thứ nhất xảy ra do bạn cố gắng gán kiểu cho mỗi biến trong một dòng. Trong C++, cách khai báo đúng là liệt kê tên biến, sau đó là kiểu dữ liệu chung cho tất cả các biến.
    - Lỗi thứ hai xảy ra do bạn cố gắng khai báo các biến có kiểu khác nhau trong cùng một câu lệnh. Mỗi biến phải được khai báo riêng với kiểu dữ liệu tương ứng.


### **Tóm tắt:**
>Trong C++, chúng ta sử dụng các **đối tượng** để truy cập vào bộ nhớ. Một đối tượng được đặt tên gọi là **biến**. Biến có một **định danh**, một **kiểu dữ liệu** và một **giá trị** (cùng một số thuộc tính khác không liên quan ở đây). **Kiểu dữ liệu** của biến được sử dụng để xác định cách giải nghĩa giá trị trong bộ nhớ.



## **Bài 1.4: <u>Gán và khởi tạo giá trị cho biến</u>**


### **Phép gán**

- Sau khi một biến đã được khai báo, bạn có thể gán cho nó một giá trị (trong một câu lệnh riêng) bằng toán tử `=`. Quá trình này được gọi là phép gán và toán tử `=` được gọi là toán tử gán.
>```
>int width; // define an integer variable named width
>width = 5; // assignment of value 5 into variable width
>// variable width now has value 5
>```
- Theo mặc định, phép gán sẽ sao chép giá trị ở vế phải của toán tử `=` sang biến ở vế trái của toán tử. Đây được gọi là gán sao chép (copy assignment).
- Ví dụ gán giá trị nhiều lần:
>```
>#include <iostream>
>
>int main()
>{
>	int width;
>	width = 5; // copy assignment of value 5 into variable width
>
>	std::cout << width; // prints 5
>
>	width = 7; // change value stored in variable width to 7
>
>	std::cout << width; // prints 7
>
>	return 0;
>}
>```
- Đoạn code này in ra:
> `57`
- Khi chúng ta gán giá trị `7` cho biến `width`, giá trị `5` trước đó sẽ bị ghi đè. Biến thông thường chỉ có thể chứa một giá trị tại một thời điểm.


### **Khởi tạo giá trị cho biến (initialization)** 

- Gán giá trị cho biến yêu cầu ít nhất hai câu lệnh: một để khai báo biến và một để gán giá trị.
- Hai bước này có thể được kết hợp. Khi một đối tượng được định nghĩa, bạn có thể tùy chọn cung cấp cho nó một giá trị ban đầu. Quá trình chỉ định giá trị ban đầu cho một đối tượng được gọi là khởi tạo (**initialization**), và cú pháp được sử dụng để khởi tạo một đối tượng được gọi là trình khởi tạo (**initializer**).
> - Ví dụ:
>```
>int width { 5 }; // Định nghĩa biến width và khởi tạo với giá trị ban đầu là 5
>
>// Biến width bây giờ có giá trị là 5
>```


### **Các dạng khởi tạo khác nhau**

- Khởi tạo trong C++ phức tạp hơn so với tưởng tượng, vì vậy chúng ta sẽ chỉ trình bày một cách đơn giản ở đây.
- Có 6 cách cơ bản để khởi tạo biến trong C++:
    >`int a; // Không có trình khởi tạo (khởi tạo mặc định)`\
    >`int b = 5; // Giá trị ban đầu sau dấu bằng (khởi tạo sao chép)`\
    >`int c( 6 ); // Giá trị ban đầu trong dấu ngoặc đơn (khởi tạo trực tiếp)`\
    >`// Phương thức khởi tạo danh sách (C++11) (ưu tiên)`\
    >`int d { 7 }; // Giá trị ban đầu trong ngoặc nhọn (khởi tạo danh sách trực tiếp)`\
    >`int e = { 8 }; // Giá trị ban đầu trong ngoặc nhọn sau dấu bằng (khởi tạo danh sách sao chép)`\
    >`int f {}; // Trình khởi tạo là ngoặc nhọn trống (khởi tạo giá trị)`
    


#### *<u>Khởi tạo mặc định (Default initialization)</u>.*

Khi không cung cấp trình khởi tạo (chẳng hạn như đối với biến `a` ở trên), thì đây được gọi là **khởi tạo mặc định**. Trong hầu hết các trường hợp, khởi tạo mặc định không thực hiện bất kỳ khởi tạo nào và để lại biến với giá trị không xác định.

#### *<u>Khởi tạo sao chép (Copy initialization)</u>.*

Khi cung cấp giá trị ban đầu sau dấu bằng, thì đây được gọi là **khởi tạo sao chép**. Hình thức khởi tạo này được thừa hưởng từ **C**.
>`int width = 5; // Khởi tạo sao chép giá trị 5 vào biến width`

Giống như gán sao chép, nó sao chép giá trị bên phải dấu bằng vào biến được tạo bên trái. Trong đoạn mã trên, biến `width` sẽ được khởi tạo với giá trị `5`.

Khởi tạo sao chép không còn được ưa chuộng trong C++ hiện đại do kém hiệu quả hơn các hình thức khởi tạo khác đối với một số kiểu dữ liệu phức tạp. Tuy nhiên, `C++17` đã khắc phục hầu hết các vấn đề này và khởi tạo sao chép hiện đang tìm lại chỗ đứng.

>**Đối với người đọc nâng cao**\
>Khởi tạo sao chép cũng được sử dụng bất cứ khi nào các giá trị được sao chép hoặc chuyển đổi ngầm, chẳng hạn như khi truyền đối số cho một hàm theo giá trị, trả về từ một hàm theo giá trị hoặc bắt các ngoại lệ theo giá trị.

#### *<u>Khởi tạo trực tiếp (Direct initialization)</u>.*

Khi cung cấp giá trị ban đầu bên trong dấu ngoặc đơn, thì đây được gọi là khởi tạo trực tiếp.

>`int width( 5 ); // Khởi tạo trực tiếp giá trị 5 vào biến width`

Khởi tạo trực tiếp ban đầu được giới thiệu để cho phép khởi tạo các đối tượng phức tạp (các đối tượng có kiểu lớp, chúng tôi sẽ đề cập trong một chương học sau) hiệu quả hơn. Giống như khởi tạo sao chép, khởi tạo trực tiếp không còn được ưa chuộng trong C++ hiện đại, chủ yếu là do nó bị thay thế bởi khởi tạo danh sách. Tuy nhiên, hiện tại chúng ta biết rằng khởi tạo danh sách có một vài điểm kỳ quặc, do đó khởi tạo trực tiếp lại được sử dụng trong một số trường hợp nhất định.

Khởi tạo trực tiếp cũng được sử dụng khi các giá trị được ép kiểu rõ ràng sang một kiểu khác.

Một trong những lý do khiến khởi tạo trực tiếp không còn được ưa chuộng là vì nó gây khó khăn trong việc phân biệt biến với hàm. Ví dụ:
>`int x();  // Khai báo trước hàm x`\
>`int x(0); // Định nghĩa biến x với giá trị khởi tạo là 0`


#### *<u>Khởi tạo danh sách (List initialization)</u>.*

Khởi tạo danh sách (List initialization) là cách thức hiện đại để khởi tạo các đối tượng trong C++. Nó còn được gọi là khởi tạo đồng nhất (uniform initialization) hoặc khởi tạo bằng ngoặc nhọn (brace initialization).

<u>Ba dạng khởi tạo danh sách:</u>

**1.** Khởi tạo danh sách trực tiếp (direct list initialization):
>`int width { 5 };    // Khởi tạo biến width với giá trị ban đầu là 5`

**2.** Khởi tạo danh sách sao chép (copy list initialization):
>`int height = { 6 }; // Gán giá trị 6 cho biến height`

**3.** Khởi tạo giá trị (value initialization):
>`int depth {};       // Khởi tạo biến depth với giá trị rỗng (sẽ được giải thích chi tiết sau)` 

Trước khi có khởi tạo danh sách:
- Trước đây, tùy thuộc vào kiểu dữ liệu, bạn cần sử dụng khởi tạo sao chép (copy initialization) hoặc khởi tạo trực tiếp (direct initialization). Khởi tạo danh sách được ra đời để cung cấp cú pháp khởi tạo thống nhất (do đó đôi khi được gọi là khởi tạo đồng nhất) hoạt động trong hầu hết các trường hợp.
- Ngoài ra, khởi tạo danh sách còn cho phép khởi tạo đối tượng với một danh sách các giá trị (do đó được gọi là khởi tạo danh sách). Ví dụ về cách khởi tạo này sẽ được giới thiệu trong bài học sau về các hàm tạo của `std::vector` và `std::list`.

<u>Lợi ích của khởi tạo danh sách:</u>
- **Ngăn chặn chuyển đổi hẹp (narrowing conversions)**: Khi sử dụng khởi tạo danh sách, việc gán các giá trị không phù hợp kiểu dữ liệu của biến sẽ gây ra lỗi. Điều này giúp tránh mất mát dữ liệu.
>`int width { 4.5 }; // Lỗi: số thập phân không thể gán cho biến nguyên`

    - Trong đoạn code trên, biến `width` kiểu `int` (chỉ lưu trữ số nguyên) nhưng chúng ta lại cố gắng gán cho nó một số thập phân (`4.5`).
    - **Khởi tạo sao chép** và **khởi tạo trực tiếp** sẽ loại bỏ phần thập phân, gán giá trị `4` cho biến `width`. Trình biên dịch của bạn có thể cảnh báo về việc mất mát dữ liệu này. Tuy nhiên, với khởi tạo danh sách, trình biên dịch bắt buộc phải báo lỗi trong trường hợp này.
- **Các phép chuyển đổi không gây mất mát dữ liệu vẫn được phép.**

<u>Tóm tắt:</u>

Khởi tạo danh sách thường được ưu tiên hơn các hình thức khởi tạo khác vì:

- Hoạt động trong hầu hết các trường hợp (tính nhất quán cao).
- Ngăn chặn chuyển đổi hẹp (tránh mất mát dữ liệu).
- Hỗ trợ khởi tạo với danh sách giá trị (sẽ được học sau).

<u>Khuyến nghị:</u>
- Trong khi học, nên ưu tiên sử dụng khởi tạo danh sách trực tiếp (hoặc khởi tạo giá trị) để khởi tạo biến.


#### *<u>Khởi tạo giá trị và khởi tạo bằng 0 (Value initialization and zero initialization)</u>.*

<u>Khởi tạo giá trị (Value initialization):</u>
- Khi bạn khởi tạo biến bằng ngoặc nhọn rỗng {}, quá trình khởi tạo giá trị (value initialization) diễn ra.
- Trong hầu hết các trường hợp, khởi tạo giá trị sẽ gán giá trị 0 cho biến (hoặc giá trị rỗng đối với kiểu dữ liệu phù hợp).
- Ví dụ:
>`int width {}; // Khởi tạo biến width với giá trị 0 (khởi tạo giá trị / khởi tạo bằng 0)`

<u>Câu hỏi:</u> *Nên dùng `{}` hay `{0}` để khởi tạo giá trị?*
- Sử dụng giá trị khởi tạo rõ ràng (`{0}`) nếu bạn thực sự sử dụng giá trị đó.
- Ví dụ:
>`int x {0};    // Khởi tạo rõ ràng biến x với giá trị 0`\
>`std::cout << x; // In ra giá trị 0`

<u>LỜI KHUYÊN:</u> Khởi tạo biến ngay khi tạo.
- Khởi tạo biến với giá trị mặc định (0, giá trị rỗng, ...) thường là lựa chọn tốt. Điều này giúp bạn tránh những vấn đề do biến chưa được khởi tạo gây ra.
- Sử dụng khởi tạo danh sách (list initialization) - Đây là cách thức hiện đại và an toàn để khởi tạo biến trong C++.


### **Khởi tạo nhiều biến trong C++**

<u>Định nghĩa nhiều biến cùng kiểu:</u>
- Trong bài trước, chúng ta đã biết có thể khai báo nhiều biến cùng kiểu trong một câu lệnh bằng cách phân cách các tên biến bằng dấu phẩy:
>`int a, b;`

- Tuy nhiên, theo khuyến cáo, bạn nên tránh sử dụng cách thức này. Tuy nhiên, vì bạn có thể gặp code cũ sử dụng cách này, nên chúng ta vẫn cần tìm hiểu thêm về nó.
- Khởi tạo nhiều biến trên cùng một dòng: Bạn có thể khởi tạo nhiều biến được khai báo trên cùng một dòng:
>```
>int a = 5, b = 6;          // Khởi tạo sao chép (copy initialization)
>int c( 7 ), d( 8 );        // Khởi tạo trực tiếp (direct initialization)
>int e { 9 }, f { 10 };     // Khởi tạo danh sách trực tiếp (direct brace initialization)
>int g = { 9 }, h = { 10 }; // Khởi tạo danh sách sao chép (copy brace initialization)
>int i {}, j {};            // Khởi tạo giá trị (value initialization)
>```

<u>Lỗi thường gặp:</u>
- Một lỗi thường gặp là lập trình viên cố gắng khởi tạo cả hai biến bằng một câu lệnh khởi tạo:
>`int a, b = 5; // Sai (biến a không được khởi tạo!`
- Cách viết chính xác:
>`int a = 5, b = 5; // Đúng`
- Trong câu lệnh sai ở trên, biến a sẽ không được khởi tạo. Trình biên dịch có thể hoặc không báo lỗi. Nếu không báo lỗi, điều này có thể khiến chương trình của bạn chạy không ổn định hoặc cho ra kết quả không mong đợi.
- **Cách nhớ để tránh lỗi:** Cách tốt nhất để nhớ đây là lỗi là xem xét trường hợp khởi tạo trực tiếp hoặc khởi tạo danh sách:
>`int a, b( 5 );  // Sai (bị hiểu nhầm là khởi tạo cho cả a và b)`\
>`int c, d{ 5 };  // Sai (bị hiểu nhầm là khởi tạo cho cả c và d)`
- Vì dấu ngoặc đơn hoặc ngoặc nhọn thường được đặt ngay cạnh tên biến, điều này khiến cho việc khởi tạo giá trị 5 chỉ dành cho biến b và d, không phải a hoặc c.





### **Cảnh báo biến được khởi tạo nhưng không sử dụng (Unused initialized variables warnings)**

- Trình biên dịch hiện đại thường sẽ cảnh báo nếu một biến được khởi tạo nhưng không được sử dụng (vì điều này hiếm khi cần thiết). Và nếu bật tùy chọn "xử lý cảnh báo như lỗi" (treat warnings as errors), các cảnh báo này sẽ được nâng cấp thành lỗi và khiến quá trình biên dịch thất bại.
- Xét ví dụ chương trình đơn giản sau:
>```
>int main()
>{
>    int x { 5 }; // Biến x được khai báo và khởi tạo
>
>    // Nhưng không được sử dụng ở bất kỳ đâu
>
>    return 0;
>}
>```
- Khi biên dịch chương trình này với trình biên dịch `g++`, lỗi sau sẽ được tạo:
>```
>prog.cc: In function 'int main()':
>prog.cc:3:9: error: unused variable 'x' [-Werror=unused-variable]
>```

Chương trình sẽ không thể biên dịch thành công.

- Có một vài cách đơn giản để khắc phục lỗi này:\
  **1. Xóa bỏ biến không sử dụng:**\
    Nếu biến `x` thực sự không được sử dụng, cách dễ nhất là xóa bỏ định nghĩa của nó (hoặc chú thích nó bằng `//`). Xóa bỏ biến không sử dụng sẽ không ảnh hưởng đến chương trình.
  
  **2. Sử dụng biến ở một nơi nào đó:**
  >```
  >#include <iostream>
  >
  >int main()
  >{
  >  int x { 5 };
  >
  >  std::cout << x; // Biến x được sử dụng
  >
  >  return 0;
  >
  >}
  >
  >```

    Tuy nhiên, cách này yêu cầu viết thêm code để sử dụng biến và có thể ảnh hưởng đến logic ban đầu của chương trình.






### **Thuộc tính `[[maybe_unused]]` trong `C++17`**


**Trường hợp không mong muốn xóa bỏ hoặc sử dụng biến:**
- Trong một số trường hợp, cả hai cách xử lý ở trên (xóa bỏ biến hoặc sử dụng biến) đều không mong muốn. Ví dụ, giả sử chúng ta có một nhóm các hằng số toán học/vật lý được sử dụng trong nhiều chương trình khác nhau:
>```
>int main()
>{
>    double pi { 3.14159 };
>    double gravity { 9.8 };
>    double phi { 1.61803 };
>
>    // Giả sử một số hằng số được sử dụng, một số không
>
>    return 0;
>}
>```
- Nếu chúng ta sử dụng các hằng số này thường xuyên, có thể chúng ta sẽ lưu chúng ở một nơi nào đó và sao chép/dán/nhập khẩu tất cả chúng cùng nhau.
- Tuy nhiên, trong bất kỳ chương trình nào mà chúng ta không sử dụng tất cả các giá trị này, trình biên dịch sẽ phàn nàn về mỗi biến không được sử dụng thực tế. Mặc dù chúng ta có thể xóa hoặc chú thích từng biến không sử dụng cho mỗi chương trình, nhưng điều này tốn thời gian và công sức. Và sau này nếu cần đến một biến đã xóa trước đó, chúng ta sẽ phải quay lại và thêm lại nó.

**Thuộc tính `[[maybe_unused]]`**
- Để giải quyết những trường hợp như vậy, `C++17` giới thiệu thuộc tính `[[maybe_unused]]`, cho phép chúng ta thông báo cho trình biên dịch rằng việc một biến không được sử dụng là chấp nhận được. Trình biên dịch sẽ không tạo ra cảnh báo về biến không sử dụng cho các biến được đánh dấu bằng thuộc tính này.
- Chương trình sau đây sẽ không tạo ra cảnh báo/lỗi:
>```
>int main()
>{
>    [[maybe_unused]] double pi { 3.14159 };
>    [[maybe_unused]] double gravity { 9.8 };
>    [[maybe_unused]] double phi { 1.61803 };
>
>    // Các biến ở trên sẽ không tạo ra cảnh báo về biến không sử dụng
>
>    return 0;
>}
>```

Ngoài ra, trình biên dịch có thể tối ưu hóa các biến này ra khỏi chương trình, vì vậy chúng không ảnh hưởng đến hiệu suất.

## **Bài 1.5: <u>Giới thiệu về `iostream`: `cout`, `cin` và `endl`</u>**


Trong bài học này, chúng ta sẽ tìm hiểu thêm về `std::cout`, đối tượng đã được sử dụng trong chương trình **"Hello world!"** để xuất văn bản **"Hello world!"** ra màn hình console. Chúng ta cũng sẽ khám phá cách lấy dữ liệu nhập từ người dùng, giúp c chương trình trở nên tương tác hơn.

### **Thư viện vào/ra:**

- Thư viện vào/ra (io library) là một phần của thư viện chuẩn C++ dùng để xử lý các tác vụ nhập và xuất cơ bản.
- Chúng ta sẽ sử dụng các chức năng trong thư viện này để lấy dữ liệu từ bàn phím và xuất dữ liệu ra màn hình console.
- Phần "io" trong "`iostream`" là viết tắt của "`input/output`" (vào/ra).

Để sử dụng các chức năng được định nghĩa trong thư viện `iostream`, chúng ta cần thêm header `iostream` vào đầu của bất kỳ tệp code nào sử dụng các nội dung được định nghĩa trong `iostream`, như sau:
>`#include <iostream>`\
>`// Phần còn lại của code sử dụng các chức năng của iostream ở đây `

### `std::cout`


Thư viện `iostream` chứa một số biến được định sẵn để chúng ta sử dụng. Một trong những biến hữu ích nhất là `std::cout`, cho phép chúng ta gửi dữ liệu đến console để in ra dưới dạng văn bản. `cout` là viết tắt của "character output" (xuất ký tự).

Ví dụ chương trình `Hello World`:

>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    std::cout << "Hello world!"; // In ra "Hello world!" ra màn hình console
>
>    return 0;
>}
>```

Trong chương trình này, chúng ta đã bao gồm `iostream` để có thể truy cập `std::cout`. Bên trong hàm `main`, chúng ta sử dụng `std::cout` cùng với toán tử chèn (`<<`) để gửi văn bản `"Hello world!"` đến console để in ra.

`std::cout` có thể in nhiều thứ:
- std::cout không chỉ in được text, mà còn có thể in cả số:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    std::cout << 4; // In số 4 ra màn hình console
>
>    return 0;
>}
>```

    Kết quả sẽ là:
> `4`

- `std::cout` cũng có thể được dùng để in giá trị của các biến:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    int x { 5 }; // Khai báo biến x kiểu int và khởi tạo giá trị 5
>    std::cout << x; // In giá trị của x (5) ra màn hình console
>
>    return 0;
>}
>```
- Để in nhiều thứ trên cùng một dòng, toán tử chèn (`<<`) có thể được sử dụng nhiều lần trong một câu lệnh duy nhất để nối (liên kết) nhiều đoạn xuất ra thành một chuỗi.
- Ví dụ:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    std::cout << "Hello" << " world!";
>    return 0;
>}
>```

    Chương trình này sẽ in ra:
> `Hello world!`
- Ví dụ in cả text và giá trị biến:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    int x { 5 };
>    std::cout << "x is equal to: " << x;
>    return 0;
>}
>```

    Chương trình này sẽ in ra:
>`x is equal to: 5`

<u>Lưu ý về tiền tố `std::`</u>

Giải thích về tiền tố `std::` sẽ được đề cập trong bài học **2.9 - Xung đột tên và Giới thiệu về Namespaces.**

### `std::endl`

- Bạn có thể nghĩ chương trình này sẽ in ra gì?
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    std::cout << "Hi!";
>    std::cout << "My name is Alex.";
>    return 0;
>}
>```

    Kết quả có thể khiến bạn bất ngờ:
    >`Hi!My name is Alex.`

- Các câu lệnh in riêng biệt (`std::cout`) không nhất thiết dẫn đến in ra các dòng riêng biệt trên console.
- **In xuống dòng chủ động:**
    - Nếu muốn in ra các dòng riêng biệt trên console, chúng ta cần thông báo cho console biết khi nào di chuyển con trỏ xuống dòng.
    - Một cách để thực hiện điều đó là sử dụng `std::endl`. Khi được xuất ra với `std::cout`, `std::endl` sẽ in một ký tự xuống dòng (`\n`) vào console (khiến con trỏ nhảy đến đầu dòng tiếp theo). Trong ngữ cảnh này, `endl` là viết tắt của "end line" (kết thúc dòng).
- Ví dụ:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout và std::endl
>
>int main()
>{
>    std::cout << "Hi!" << std::endl; // std::endl sẽ khiến con trỏ nhảy xuống dòng tiếp theo
>    std::cout << "My name is Alex." << std::endl;
>
>    return 0;
>}
>```

    Chương trình này sẽ in ra:
    >`Hi!`\
    >`My name is Alex.`

>**Mẹo:**
>Mẹo về `std::endl`:
>
>Trong chương trình trên, `std::endl` thứ hai về mặt kỹ thuật không cần thiết, vì chương trình kết thúc ngay sau đó. Tuy nhiên, nó có một vài mục đích hữu ích.
>
>Thứ nhất, nó giúp chỉ ra rằng dòng xuất ra là một "hoàn chỉnh" (chứ không phải là đầu ra một phần được hoàn thành ở đâu đó sau trong code). Theo nghĩa này, nó hoạt động tương tự như việc sử dụng dấu chấm trong tiếng Anh.
>
>Thứ hai, nó đặt con trỏ trên dòng tiếp theo, vì vậy nếu sau này chúng ta thêm các dòng xuất ra bổ sung (ví dụ: yêu cầu chương trình nói "bye!"), các dòng đó sẽ xuất hiện ở vị trí mong đợi (chứ không phải được nối vào dòng xuất ra trước đó).
>
>Thứ ba, sau khi chạy một file thực thi từ dòng lệnh, một số hệ điều hành không xuất ra dòng mới trước khi hiển thị lại dấu nhắc lệnh. Nếu chương trình của chúng ta không kết thúc với con trỏ trên một dòng mới, dấu nhắc lệnh có thể xuất hiện được nối vào dòng xuất ra trước đó, thay vì ở đầu dòng mới như người dùng mong đợi.
>



### **`std::cout` được đệm (buffered)**

Hãy tưởng tượng về một tàu lượn siêu tốc ở công viên giải trí yêu thích của bạn. Khách tham quan đến (với tốc độ thay đổi) và xếp hàng. Theo định kỳ, một toa tàu đến và chở khách (tối đa bằng sức chứa của toa tàu). Khi toa tàu đầy hoặc đủ thời gian đã trôi qua, toa tàu khởi hành với một nhóm hành khách và bắt đầu chuyến đi. Bất kỳ hành khách nào không thể lên toa tàu hiện tại sẽ đợi toa tàu tiếp theo.

Cách thức hoạt động này tương tự như cách dữ liệu xuất ra được gửi đến `std::cout` thường được xử lý trong C++. Các câu lệnh trong chương trình của chúng ta yêu cầu gửi dữ liệu xuất ra cho console. Tuy nhiên, dữ liệu xuất ra đó thường không được gửi ngay lập tức tới console. Thay vào đó, dữ liệu xuất ra được yêu cầu sẽ "xếp hàng" và được lưu trữ trong một vùng nhớ được dành riêng để thu thập các yêu cầu như vậy (gọi là **bộ đệm** - **buffer**). Định kỳ, bộ đệm sẽ được "xả" (`flush`), nghĩa là tất cả dữ liệu được thu thập trong bộ đệm được chuyển đến đích của nó (trong trường hợp này là console).



> **Chú thích của tác giả:**\
> Theo một phép ẩn dụ khác, việc xả bộ đệm giống như xả nước bồn cầu. Tất cả "dữ liệu xuất ra" được thu thập của bạn sẽ được chuyển đến bất cứ nơi nào nó sẽ đến tiếp theo. (Không hay cho lắm!)

Điều này cũng có nghĩa là nếu chương trình của bạn bị lỗi, dừng đột ngột (abort) hoặc tạm dừng (ví dụ: để gỡ lỗi) trước khi bộ đệm được xả, bất kỳ dữ liệu xuất ra nào vẫn còn chờ trong bộ đệm sẽ không được hiển thị.



> **Lưu ý quan trọng:**
>
>Trái ngược với xuất ra được đệm là xuất ra không được đệm (unbuffered output). Với xuất ra không được đệm, mỗi yêu cầu xuất ra riêng lẻ sẽ được gửi trực tiếp đến thiết bị đầu ra.
>
>Viết dữ liệu vào bộ đệm thường nhanh, trong khi truyền một loạt dữ liệu đến thiết bị đầu ra thì tương đối chậm. Việc đệm có thể cải thiện hiệu suất đáng kể bằng cách giảm thiểu số lượng truyền chậm cần thực hiện khi có nhiều yêu cầu xuất ra.

### **`std::endl` vs ‘`\n`’**



Trong C++, `std::endl` và '`\n`' đều được sử dụng để in xuống dòng, nhưng chúng có sự khác biệt về mặt hiệu quả:
- `std::endl`:
    - Thực hiện hai tác vụ:
        - Di chuyển con trỏ xuống dòng tiếp theo trên console.
        - Xả (flush) bộ đệm của `std::cout`. Bộ đệm là một vùng nhớ tạm thời lưu trữ dữ liệu xuất ra trước khi gửi đến console.
    - Xả bộ đệm có thể hơi kém hiệu quả vì nó liên quan đến việc ghi dữ liệu ra thiết bị đầu ra ngay cả khi chưa cần thiết.
- '`\n`'
    - Chỉ thực hiện một tác vụ: di chuyển con trỏ xuống dòng tiếp theo.
    - Không xả bộ đệm. Hệ thống sẽ tự động xả bộ đệm theo định kỳ, thường là một cách hiệu quả hơn.
    - Thường được ưu tiên sử dụng hơn vì nó:
        - Hiệu quả hơn: Tránh việc xả bộ đệm không cần thiết.
        - Gọn nhẹ hơn: Dễ gõ hơn `std::endl`.
        - Linh hoạt hơn: Có thể nhúng vào trong chuỗi ký tự.
    - Ví dụ:
    >```
    >#include <iostream> // for std::cout
    >
    >int main()
    >{
    >    int x { 5 };
    >    std::cout << "x is equal to: " << x << '\n'; // Sử dụng '\n' đơn lẻ
    >    std::cout << "And that's all, folks!\n"; // Nhúng '\n' vào chuỗi ký tự (dùng dấu ngoặc kép đôi, không dùng đơn)
    >    return 0;
    >}
    >```

    - Kết quả:
    >`x is equal to: 5`\
    >`And that's all, folks!`
  - Lưu ý về cách sử dụng ký tự xuống dòng ('`\n`')
    - Khi sử dụng một mình để xuống dòng, '`\n`' cần được đặt trong dấu ngoặc đơn.
    - Khi nhúng vào chuỗi ký tự được bao bọc bởi dấu ngoặc kép đôi, không cần thêm dấu ngoặc đơn cho '`\n`'.

>**Thực hành tốt nhất:**\
>Sử dụng '`\n`' thay vì `std::endl` khi in ra văn bản trên console để cải thiện hiệu suất.

>**Cảnh báo:**
> - '`\n`' sử dụng dấu gạch chéo ngược (`\`) để biểu thị ký tự đặc biệt (giống như tất cả các ký tự đặc biệt trong C++), không phải là dấu gạch chéo xuôi (`/`).
> - Sử dụng dấu g/ạch chéo xuôi (`/n`) hoặc bao gồm các ký tự khác bên trong dấu ngoặc đơn (ví dụ: '` \n`' hoặc '`.\n') sẽ dẫn đến kết quả không mong đợi.

### `std::cin`

- `std::cin` là một biến được định sẵn khác trong thư viện `iostream`.
- Trong khi `std::cout` in dữ liệu ra console sử dụng toán tử chèn (`<<`), thì `std::cin` (viết tắt của "character input" - nhập ký tự) đọc dữ liệu nhập từ bàn phím bằng toán tử trích xuất (`>>`).
- Dữ liệu nhập phải được lưu trữ trong một biến để sử dụng.
- Ví dụ:
>```
>#include <iostream>
>
>int main () {
>	int x;   // định nghĩa biến x để chứa đầu vào của người dùng (và khởi tạo giá trị cho nó)
>	std::cout << "Enter a number: ";	// yêu cầu người dùng nhập số
>	std::cin >> x;                      // lấy số từ bàn phím và lưu trữ trong biến x
>	std::cout << "You entered " << x << '\n';
>	return 0;
>}
>```

Hãy thử biên dịch và chạy chương trình này. Khi bạn chạy chương trình, dòng `5` sẽ in ra "`Enter a number: `". Khi mã đến dòng `8`, chương trình sẽ chờ bạn nhập dữ liệu. Sau khi bạn nhập một số (và nhấn `enter`), số bạn nhập sẽ được gán cho biến `x`. Cuối cùng, trên dòng `10`, chương trình sẽ in ra "`You entered `" theo sau là số bạn vừa nhập.

Ví dụ (tôi nhập 4):
>`Enter a number: 4`\
>`You entered 4`
 
Đây là một cách đơn giản để lấy dữ liệu nhập từ bàn phím của người dùng và chúng ta sẽ sử dụng nó trong nhiều ví dụ sắp tới. Lưu ý rằng bạn không cần sử dụng '`\n`' khi chấp nhận đầu vào, vì người dùng sẽ cần nhấn phím `enter` để đầu vào của họ được chấp nhận và điều này sẽ di chuyển con trỏ xuống dòng tiếp theo trên console.

**Đọc nhiều số trên một dòng:**
- Trong C++, bạn có thể sử dụng toán tử trích xuất (`>>`) để đọc nhiều giá trị được phân cách bởi khoảng trắng (thường là dấu cách hoặc tab) từ đầu vào tiêu chuẩn (`std::cin`) và lưu trữ chúng vào các biến khác nhau.
- Dưới đây là một ví dụ được cải tiến kết hợp các phương pháp hay nhất:

>```
>#include <iostream>  // for std::cout and std::cin
>
>int main()
>{
>    std::cout << "Enter two numbers seperated by a space: ";
>
>    int x, y;       // define variable x and y to hold user input
>    std::cin >> x >> y; // get number from keyboard and store it in variable x
>
>    std::cout << "You entered " << x << " and " << y << '\n';
>    return 0;
>}
>```

- Chương trình sẽ in ra:
>`Enter two numbers seperated by a space:  5 6`\
>`You entered 5 and 6`

>**Thực tiễn**\
>Mặc dù giá trị do người dùng cung cấp từ `std::cin` cuối cùng sẽ ghi đè lên giá trị khởi tạo, nhưng có một số lý do chính đáng để khởi tạo biến trước khi sử dụng chúng với `std::cin`:
> - **Rõ ràng và minh bạch**: Khởi tạo làm cho code của bạn dễ đọc hơn và thể hiện rõ ràng về kiểu dữ liệu dự định và giá trị mặc định tiềm năng của biến. Nó làm rõ rằng biến không được sử dụng trong trạng thái chưa được khởi tạo, điều này có thể dẫn đến hành vi không mong đợi.
> - **Xử lý lỗi**: Nếu `std::cin` gặp phải đầu vào không hợp lệ không thể chuyển đổi thành kiểu biến mong đợi (ví dụ: nhập chuỗi trong khi cần số nguyên), trạng thái của biến sẽ `become undefined` (trở nên không xác định). Tuy nhiên, nếu biến được khởi tạo trước, bạn có thể có một giá trị mặc định đã biết để làm việc, `potentially aiding in error handling` (có khả năng hỗ trợ trong việc xử lý lỗi).
> - **Tính nhất quán**: Thực thi việc khởi tạo như một practice (thực hành) chung thúc đẩy phong cách code nhất quán và giảm thiểu rủi ro gây ra lỗi do vô tình sử dụng các biến chưa được khởi tạo ở các phần khác của code.







## **Bài 1.6: <u>Biến chưa được khởi tạo trong C/C++</u>**

**Không giống như một số ngôn ngữ lập trình khác, C/C++ không tự động khởi tạo hầu hết các biến thành một giá trị nhất định (chẳng hạn như 0).** Khi một biến chưa được khởi tạo được cấp một địa chỉ bộ nhớ để lưu trữ dữ liệu, giá trị mặc định của biến đó là bất kỳ giá trị "rác" (garbage value) nào có sẵn trong địa chỉ bộ nhớ đó! Biến chưa được gán một giá trị đã biết (thông qua khởi tạo hoặc gán) được gọi là **biến chưa được khởi tạo** (**uninitialized variable**).

>**Thuật ngữ**\
>Nhiều người đọc mong đợi các thuật ngữ "được khởi tạo" (**initialized**) và "chưa được khởi tạo" (**uninitialized**) là hoàn toàn đối lập, nhưng chúng không hẳn như vậy! Trong ngôn ngữ thông thường, "được khởi tạo" có nghĩa là đối tượng được cung cấp một giá trị ban đầu tại thời điểm khai báo. "Chưa được khởi tạo" có nghĩa là đối tượng chưa được gán một giá trị đã biết (bằng bất kỳ phương thức nào, bao gồm cả gán). Do đó, một đối tượng không được khởi tạo nhưng sau đó được gán một giá trị thì không còn là chưa được khởi tạo (bởi vì nó đã được cung cấp một giá trị đã biết).

>**Tóm tắt**
>- Khởi tạo = Đối tượng được cung cấp một giá trị đã biết tại thời điểm khai báo.
>- Gán = Đối tượng được cung cấp một giá trị đã biết sau thời điểm khai báo.
>- Chưa được khởi tạo = Đối tượng chưa được cung cấp một giá trị đã biết.

Liên quan đến điều đó, hãy xem xét định nghĩa biến này:
>`int x;`

Trong bài học **1.4 - Gán và khởi tạo biến**, chúng tôi đã lưu ý rằng khi không cung cấp trình khởi tạo, biến sẽ được khởi tạo mặc định. Trong hầu hết các trường hợp (chẳng hạn như trường hợp này), khởi tạo mặc định không thực hiện khởi tạo thực tế. Do đó, chúng ta có thể nói `x` là chưa được khởi tạo. Chúng ta tập trung vào kết quả (đối tượng chưa được cung cấp một giá trị đã biết), chứ không phải quá trình.

>**Ngoài lề**\
>Sự thiếu khởi tạo này là một tối ưu hóa hiệu suất được thừa hưởng từ C, quay lại thời điểm máy tính còn chậm. Hãy tưởng tượng trường hợp bạn sẽ đọc 100.000 giá trị từ một file. Trong trường hợp đó, bạn có thể tạo 100.000 biến, sau đó điền chúng bằng dữ liệu từ file.
>
>Nếu C++ khởi tạo tất cả các biến đó với các giá trị mặc định khi tạo, điều này sẽ dẫn đến 100.000 lần khởi tạo (có thể chậm) và mang lại lợi ích rất ít (vì bạn đang ghi đè lên các giá trị đó dù sao).
>
>Hiện tại, bạn luôn nên khởi tạo các biến của mình vì chi phí thực hiện việc đó không đáng kể so với lợi ích. Khi bạn đã thoải mái hơn với ngôn ngữ, có thể có một số trường hợp nhất định bạn bỏ qua việc khởi tạo vì mục đích tối ưu hóa. Nhưng điều này luôn được thực hiện một cách chọn lọc và cố ý.

**Sử dụng giá trị của các biến chưa được khởi tạo có thể dẫn đến kết quả không mong đợi.** Hãy xem xét chương trình ngắn sau đây:
>```
>#include <iostream>
>
>int main()
>{
>    // Định nghĩa một biến integer có tên x
>    int x; // Biến này chưa được khởi tạo vì chúng tôi chưa gán giá trị cho nó
>
>    // In giá trị của x lên màn hình
>    std::cout << x << '\n'; // Ai biết chúng ta sẽ nhận được gì, vì x chưa được khởi tạo
>
>    return 0;
>}
>```

Trong trường hợp này, máy tính sẽ gán một số bộ nhớ chưa sử dụng cho `x`. Sau đó, nó sẽ gửi giá trị nằm trong vị trí bộ nhớ đó tới `std::cout`, giá trị này sẽ in giá trị (được hiểu là số nguyên). Nhưng nó sẽ in ra giá trị gì? Câu trả lời là “ai biết được!”, và câu trả lời có thể (hoặc không) thay đổi mỗi khi bạn chạy chương trình. Khi tác giả chạy chương trình này trong Visual Studio, `std::cout` đã in giá trị `7177728` một lần và `5277592` tiếp theo. Hãy thoải mái biên dịch và chạy chương trình (máy tính của bạn sẽ không nổ đâu).


Hầu hết các trình biên dịch hiện đại sẽ cố gắng phát hiện xem một biến có đang được sử dụng mà chưa được gán giá trị hay không. Nếu phát hiện 
được, chúng thường sẽ đưa ra cảnh báo hoặc lỗi thời gian biên dịch. Ví dụ, biên dịch chương trình trên trong Visual Studio sẽ tạo ra cảnh báo sau:

>`c:\VCprojects\test\test.cpp(11) : warning C4700: uninitialized local variable 'x' used`

Đối với `g++`:
>```
>exp1_6a.cpp: In function ‘int main()’:
>exp1_6a.cpp:9:23: error: ‘x’ is used uninitialized [-Werror=uninitialized]
>    9 |     std::cout << x << '\n'; // Ai biết chúng ta sẽ nhận được
> gì, vì x chưa được khởi tạo
>      |                       ^~~~
>exp1_6a.cpp:6:9: note: ‘x’ was declared here
>    6 |     int x; // Biến này chưa được khởi tạo vì chúng tôi chưa 
>gán giá trị cho nó
>      |         ^
>cc1plus: all warnings being treated as errors
>```

Nếu trình biên dịch của bạn không cho phép biên dịch và chạy chương trình trên (ví dụ: vì nó coi vấn đề này là lỗi), thì đây là một giải pháp khả thi để giải quyết vấn đề này:

>```
>#include <iostream>
>
>void doNothing(int&) // Đừng lo lắng về '&' là gì lúc này, chúng tôi chỉ sử dụng nó để đánh lừa trình biên dịch nghĩ rằng biến x được sử dụng
>{
>}
>
>int main()
>{
>    // Khai báo biến nguyên x
>    int x; // Biến này chưa được khởi tạo
>
>    doNothing(x); // Đánh lừa trình biên dịch nghĩ rằng chúng ta đang gán giá trị cho biến này
>
>    // In giá trị của x lên màn hình (ai biết được chúng ta sẽ nhận được gì, vì x chưa được khởi tạo).
>    std::cout << x << '\n';
>
>    return 0;
>}

Sử dụng biến chưa được khởi tạo là một trong những lỗi phổ biến nhất mà lập trình viên mới mắc phải và không may, nó cũng có thể là một trong những lỗi khó gỡ lỗi nhất (vì chương trình vẫn có thể chạy tốt nếu biến chưa được khởi tạo tình cờ được gán vào một vùng nhớ có giá trị hợp lý, chẳng hạn như 0).

Đây là lý do chính cho nguyên tắc hay thực hành tốt nhất là *“luôn khởi tạo các biến của bạn”*.


### **Hành vi bất định (Undefined Behavior)**


Sử dụng giá trị từ một biến chưa được khởi tạo là ví dụ đầu tiên của chúng tôi về hành vi bất định (undefined behavior). Hành vi bất định (thường được viết tắt là UB) là kết quả của việc thực thi đoạn mã mà hành vi của nó không được xác định rõ ràng bởi ngôn ngữ C++. Trong trường hợp này, ngôn ngữ C++ không có bất kỳ quy tắc nào quy định điều gì sẽ xảy ra nếu bạn sử dụng giá trị của một biến chưa được gán giá trị đã biết. Do đó, nếu bạn thực sự làm điều này, hành vi bất định sẽ xảy ra.

Mã triển khai hành vi bất định có thể biểu hiện bất kỳ triệu chứng nào sau đây:
- Chương trình của bạn tạo ra các kết quả khác nhau mỗi lần chạy.
- Chương trình của bạn luôn tạo ra cùng một kết quả không chính xác.
- Chương trình của bạn hoạt động không nhất quán (đôi khi tạo ra kết quả chính xác, đôi khi không).
- Chương trình của bạn dường như hoạt động nhưng tạo ra kết quả không chính xác sau này trong chương trình.
- Chương trình của bạn bị treo, ngay lập tức hoặc sau đó.
- Chương trình của bạn hoạt động trên một số trình biên dịch nhưng không hoạt động trên các trình biên dịch khác.
- Chương trình của bạn hoạt động cho đến khi bạn thay đổi một số đoạn mã khác dường như không liên quan.

>**Lưu ý của tác giả:**\
>Hành vi bất định giống như một hộp sôcôla. Bạn không bao giờ biết mình sẽ nhận được gì!

C++ chứa nhiều trường hợp có thể dẫn đến hành vi bất định nếu bạn không cẩn thận. Chúng tôi sẽ chỉ ra những điều này trong các bài học tương lai bất cứ khi nào chúng tôi gặp chúng. Hãy ghi nhớ những trường hợp này và đảm bảo bạn tránh chúng.

>**Nguyên tắc:**\
>Cẩn thận tránh tất cả các tình huống dẫn đến hành vi bất định, chẳng hạn như sử dụng biến chưa được khởi tạo.


### **Hành vi phụ thuộc trình biên dịch (Implementation-defined behavior) và hành không được chỉ định rõ ràng (Unspecified behavior)**



#### <u>*Hành vi phụ thuộc trình biên dịch:*</u>

- Đây là cách xử lý của một số cú pháp nhất định do trình biên dịch (compiler) quyết định.
- Các hành vi này phải nhất quán và được ghi nhận trong tài liệu của trình biên dịch, nhưng kết quả có thể khác nhau giữa các trình biên dịch khác nhau.
- **Ví dụ:**
>```
>#include <iostream>
>
>int main() {
>  std::cout << sizeof(int) << '\n'; // In ra kích thước bộ nhớ cần thiết cho một kiểu int
>  return 0;
>}
>```

    Trong hầu hết các hệ thống, đoạn code này sẽ in ra giá trị `4`, nhưng trên một số hệ thống khác, nó có thể in ra giá trị `2`. Điều này phụ thuộc vào cách trình biên dịch trên từng nền tảng phân bổ bộ nhớ cho kiểu dữ liệu `int`.




#### <u>*Hành vi không được chỉ định rõ ràng (Unspecified Behaviour):*</u>

- Giống với hành vi phụ thuộc trình biên dịch, hành vi không được chỉ định rõ ràng phụ thuộc vào cách trình biên dịch xử lý, nhưng không bắt trình biên dịch phải ghi nhận lại hành vi đó.
Ví dụ: 
- Thứ tự đánh giá (evaluate) các biểu thức con, thứ tự đánh giá các đối số truyền vào hàm là không được chỉ định rõ ràng, đây là unspecified behaviour.

#### *Tại sao nên tránh*

Cả hai loại hành vi lỗi này đều có thể dẫn đến việc chương trình hoạt động không như mong đợi khi được biên dịch trên một trình biên dịch khác, hoặc thậm chí trên cùng một trình biên dịch nếu bạn thay đổi các cài đặt dự án ảnh hưởng đến cách thức hoạt động của trình biên dịch.

## <u>**Bài 1.7: Từ khóa và cách đặt tên định danh**</u>

C++ dành riêng một bộ gồm 92 từ (tính đến C++23) được định nghĩa sẵn. Những từ này được gọi là từ khóa (hoặc từ dành riêng), mỗi từ khóa đều có một ý nghĩa đặc biệt trong ngôn ngữ C++.

| `alignas`<br>`alignof`<br>`and`<br>`and_eq`<br>`asm`<br>`auto`<br>`bitand`<br>`bitor`<br>`bool`<br>`break`<br>`case`<br>`catch`<br>`char`<br>`char8_t` (since `C++20`)<br>`char16_t`<br>`char32_t`<br>`class`<br>`compl`<br>`concept` (since `C++20`)<br>`const`<br>`consteval` (since `C++20`)<br>`constexpr`<br>`constinit` (since `C++20`) | `const_cast`<br>`continue`<br>`co_await` (since `C++20`)<br>`co_return` (since `C++20`)<br>`co_yield` (since `C++20`)<br>`decltype`<br>`default`<br>`delete`<br>`do`<br>`double`<br>`dynamic_cast`<br>`else`<br>`enum`<br>`explicit`<br>`export`<br>`extern`<br>`false`<br>`float`<br>`for`<br>`friend`<br>`goto`<br>`if`<br>`inline` | `int`<br>`long`<br>`mutable`<br>`namespace`<br>`new`<br>`noexcept`<br>`not`<br>`not_eq`<br>`nullptr`<br>`operator`<br>`or`<br>`or_eq`<br>`private`<br>`protected`<br>`public`<br>`register`<br>`reinterpret_cast`<br>`requires` (since `C++20`)<br>`return`<br>`short`<br>`signed`<br>`sizeof`<br>`static` | `static_assert`<br>`static_cast`<br>`struct`<br>`switch`<br>`template`<br>`this`<br>`thread_local`<br>`throw`<br>`true`<br>`try`<br>`typedef`<br>`typeid`<br>`typename`<br>`union`<br>`unsigned`<br>`using`<br>`virtual`<br>`void`<br>`volatile`<br>`wchar_t`<br>`while`<br>`xor`<br>`xor_eq` |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|

>Lưu ý: Các từ khóa được đánh dấu (C++20) được thêm vào trong C++20. Nếu trình biên dịch của bạn không hỗ trợ C++20 (hoặc có chức năng C++20 nhưng mặc định bị tắt), các từ khóa này có thể không hoạt động.

C++ cũng định nghĩa các định danh đặc biệt: `override`, `final`, `import` và `module`. Chúng có ý nghĩa cụ thể khi được sử dụng trong một số ngữ cảnh nhất định nhưng không bị dành riêng trong các trường hợp khác.

Bạn có thể đã gặp một số từ khóa này, bao gồm `int` và `return`. Cùng với một tập hợp các toán tử, các từ khóa và định danh đặc biệt này định nghĩa toàn bộ ngôn ngữ **C++** (ngoại trừ các lệnh tiền xử lý). Bởi vì từ khóa và định danh đặc biệt có ý nghĩa đặc biệt, IDE của bạn có thể thay đổi màu sắc của các từ này để làm chúng nổi bật so với các định danh khác.

Khi hoàn thành loạt bài hướng dẫn này, bạn sẽ hiểu được ý nghĩa của hầu hết các từ khóa này!

### **Quy tắc đặt tên cho định danh (Identifier naming rules)**

Như một lời nhắc nhở, tên của một biến (hoặc hàm, kiểu dữ liệu, hoặc loại đối tượng khác) được gọi là định danh (**identifier**). C++ cung cấp cho bạn nhiều sự linh hoạt để đặt tên cho các định danh theo ý muốn. Tuy nhiên, có một vài quy tắc cần tuân theo khi đặt tên cho định danh:

**1. Không trùng với từ khóa:** Từ khóa là các từ được C++ dành riêng để sử dụng cho các mục đích nội bộ của ngôn ngữ và không thể được dùng làm tên cho các định danh.\
**2. Ký tự hợp lệ:** Tên định danh chỉ được bao gồm các ký tự sau:\
    - Chữ cái (in hoa hoặc thường)\
    - Số\
    - Ký tự gạch dưới (_) \
    **Lưu ý:** Không được chứa các ký hiệu khác (ngoại trừ dấu gạch dưới) hoặc khoảng trắng (dấu cách hoặc tab).\
**3. Bắt đầu bằng chữ cái hoặc dấu gạch dưới:** Tên định danh phải bắt đầu bằng một chữ cái (in hoa hoặc thường) hoặc dấu gạch dưới. Không được bắt đầu bằng số.\
**4. Phân biệt chữ hoa/thường:** **C++** phân biệt chữ hoa và chữ thường, do đó `nvalue` khác với `nValue` và khác với `NVALUE`.


### **Quy tắc ngón tay cái về cách đặt tên định danh:**

Bây giờ bạn đã biết có thể đặt tên cho biến như thế nào, chúng ta hãy thảo luận về **nên** đặt tên cho biến (hoặc hàm) như thế nào.

#### <u>*Quy tắc khuyên dùng:*</u>

1. **Chữ cái thường ở đầu:**
- Theo quy ước trong C++, tên biến nên bắt đầu bằng một chữ cái thường. Nếu tên biến là một từ đơn hoặc viết tắt, toàn bộ tên nên được viết thường.

>`int giaTri; // Theo quy ước (conventional)`
>
>`int GiaTri; // Không theo quy ước (nên bắt đầu bằng chữ thường)`\
>`int GIA_TRI; // Không theo quy ước (nên bắt đầu bằng chữ thường và viết toàn bộ chữ thường)`\
>`int GiATrI; // Không theo quy ước (bạn nên gặp bác sĩ tâm lý) ;)`

2. **Tên hàm:**
- Tên hàm thường cũng được bắt đầu bằng một chữ cái thường (mặc dù có một số ý kiến ​​khác nhau về điểm này). Chúng ta sẽ tuân theo quy ước này, vì hàm chính `main` (mà tất cả các chương trình phải có) bắt đầu bằng chữ thường, giống như tất cả các hàm trong thư viện chuẩn C++.
3. **Chữ cái hoa cho kiểu dữ liệu:**
- Tên định danh bắt đầu bằng chữ cái in hoa thường được sử dụng cho các kiểu dữ liệu do người dùng tự định nghĩa (chẳng hạn như cấu trúc (**struct**), lớp (**class**) và liệt kê (**enum**), tất cả sẽ được đề cập sau).
4. **Cụm từ:**
- Nếu tên biến hoặc hàm là nhiều từ, thì có hai quy ước phổ biến: phân cách các từ bằng dấu gạch dưới (đôi khi được gọi là `snake_case` (quy tắc con rắn)) hoặc viết hoa các chữ cái đầu (đôi khi được gọi là `camelCase` (quy tắc lạc đà), vì các chữ cái in hoa nhô lên giống như bướu trên lưng lạc đà).
- Ví dụ:
>`int ten_bien_cua_toi;  // Theo quy ước (phân cách bằng dấu gạch dưới/snake_case)`\
>`int ten_ham_cua_toi(); // Theo quy ước (phân cách bằng dấu gạch dưới/snake_case)`
>
>`int TenBienCuaToi;     // Theo quy ước (viết hoa các chữ cái đầu/camelCase)`\
>`int TenHamCuaToi();   // Theo quy ước (viết hoa các chữ cái đầu/camelCase)`
>
>`int ten bien cua toi;  // Không hợp lệ (khoảng trắng không được phép)`\
>`int ten ham cua toi(); // Không hợp lệ (khoảng trắng không được phép)`
>
>`int TenBienCuaToi;     // Không theo quy ước (nên bắt đầu bằng chữ thường)`\
>`int TenHamCuaToi();   // Không theo quy ước (nên bắt đầu bằng chữ thường)`

Trong hướng dẫn này, chúng tôi thường sử dụng cách viết hoa các chữ cái đầu vì nó dễ đọc hơn (dễ dàng nhầm lẫn dấu gạch dưới với khoảng trắng trong các khối mã dày đặc). Nhưng thông thường, cả hai cách đều được sử dụng - thư viện chuẩn C++ sử dụng phương pháp dấu gạch dưới cho cả biến và hàm. Đôi khi bạn sẽ thấy sự kết hợp của cả hai: quy tắc con rắn được sử dụng cho biến và quy tắc lạc đà được sử dụng cho hàm.

Điều đáng lưu ý là nếu bạn đang làm việc với mã của người khác, thì nhìn chung nên tuân theo phong cách của mã bạn đang làm việc hơn là tuân theo quy ước đặt tên một cách cứng nhắc như đã nêu ở trên.

>**Thực tiễn:**
> - Khi làm việc trong một chương trình hiện có, hãy sử dụng các quy ước của chương trình đó (ngay cả khi chúng không tuân theo các quy tắc hiện đại).
> - Sử dụng các quy tắc được khuyên dùng ở trên khi bạn đang viết chương trình mới.


#### <u>*Quy tắc nên tránh:*</u>

5. **Tránh dấu gạch dưới ở đầu:**
- Bạn nên tránh đặt tên định danh bắt đầu bằng dấu gạch dưới, vì những tên này thường được dành riêng cho hệ điều hành, thư viện hoặc trình biên dịch sử dụng.
6. **Tên không rõ nghĩa:**
- Thứ ba, tên định danh của bạn nên thể hiện rõ ràng ý nghĩa của giá trị mà chúng lưu trữ (đặc biệt nếu đơn vị giá trị biến không rõ ràng). Tên định danh nên được đặt tên theo cách giúp người không biết gì về mã của bạn có thể hiểu được nó nhanh nhất có thể. Ba tháng sau, khi bạn xem lại chương trình của mình, bạn sẽ quên cách hoạt động của nó và sẽ tự cảm ơn bản thân vì đã chọn những tên biến có ý nghĩa.
- Tuy nhiên, đặt tên quá phức tạp cho một biến đơn giản sẽ cản trở việc hiểu tổng thể về những gì chương trình đang làm, gần giống như việc đặt tên không chính xác cho một định danh được sử dụng rộng rãi. Do đó, một nguyên tắc hay là làm cho độ dài của tên định danh tương ứng với mức độ phổ biến của nó. Một định danh có công dụng đơn giản có thể có tên ngắn (ví dụ: `i`). Một định danh được sử dụng rộng rãi hơn (ví dụ: hàm được gọi từ nhiều vị trí khác nhau trong chương trình) nên có tên dài hơn và mô tả nhiều hơn (ví dụ: thay vì `open`, hãy thử `openFileOnDisk`).



>`int dem_k; //không tốt, k nghĩa là gì sau dem`\
>`int soLuongKhachHang; //Tốt, thể hiện số lượng gì đang được đếm`\
>`int i; //Tùy trường hợp có thể tốt hoặc tệ`\
>`int chiSo; //Tùy trường hợp, nếu ta biết đang làm gì`\
>`int tongDiem; //Tùy trường hợp, tốt nếu chỉ có 1 tổng được tính, nếu không thì khá mơ hồ`\
>`int _dem; //Không tốt, tên biến không nên bắt đầu bằng dấu gạch dưới`\
>`int dem; //Tùy trường hợp, nếu chúng ta biết đang đếm cái gì`\
>`int data;	//Không tốt, loại dữ liệu gì?`\
>`int time;	//Không tốt, biến đếm thời gian theo đơn vị gì? Giờ, hay phút, giây?`\
>`int soPhutDaChay; //Tốt, mô tả rõ ràng`\
>`int giaTri1, giaTri2; //Tùy trường hợp, khó phân biệt giữa 2 biến`\
>`int soTao; //Tốt, mô tả rõ ràng`\
>`int soQuaiGietDuoc; //Tốt`\
>`int x, y; //Tùy trường hợp, có thể tốt hoặc không`

7. **Tránh viết tắt:**
- Trong mọi trường hợp, hãy tránh sử dụng các viết tắt (trừ khi chúng phổ biến/không gây nhầm lẫn). Mặc dù chúng giúp giảm thời gian bạn cần để viết code, nhưng chúng lại khiến code của bạn khó đọc hơn. Code được đọc nhiều hơn so với việc viết, thời gian bạn tiết kiệm khi viết code sẽ là thời gian mà mọi người đọc nó, bao gồm cả bạn trong tương lai, lãng phí khi đọc. Nếu bạn muốn viết code nhanh hơn, hãy sử dụng tính năng tự động hoàn thành (auto completion) của trình soạn thảo.
8. **Lười comment:**
- Đối với việc khai báo biến, việc sử dụng comment để mô tả biến sẽ được sử dụng để làm gì hoặc giải thích bất kỳ điều gì khác có thể không rõ ràng là rất hữu ích. Ví dụ: giả sử chúng tôi đã khai báo một biến có tên `soKyTu` được cho là lưu trữ số ký tự trong một đoạn văn bản. Đoạn văn bản **"Hello World!"** có 10, 11 hay 12 ký tự? Nó phụ thuộc vào việc chúng ta có bao gồm khoảng trắng hoặc dấu câu hay không. Thay vì đặt tên biến là `soKyTuBaoGomKhoangTrangVaDauCau`, thì một comment được đặt đúng chỗ trên hoặc bên trên dòng khai báo sẽ giúp người dùng hiểu được:
>`// Số lượng ký tự trong một đoạn văn bản, bao gồm cả khoảng trắng và dấu câu`\
>`int soKyTu;`

## **Bài 1.8: <u>Khoảng trắng và Định dạng cơ bản trong C++</u>**

**Khoảng trắng (Whitespace)** là một thuật ngữ chỉ các ký tự được sử dụng cho mục đích định dạng. Trong **C++**, nó chủ yếu đề cập đến **dấu cách**, **tab** và **xuống dòng** (**newline**). Khoảng trắng trong C++ thường được dùng cho 3 mục đích: phân cách các thành phần ngôn ngữ nhất định, xuất hiện bên trong văn bản và định dạng code.

### 1. **Phân cách các thành phần ngôn ngữ:**

- Cú pháp của ngôn ngữ yêu cầu một số thành phần được phân cách bằng khoảng trắng. Điều này chủ yếu xảy ra khi hai từ khóa hoặc định danh cần được đặt cạnh nhau, để trình biên dịch có thể phân biệt chúng.
- Ví dụ: Khai báo biến phải được phân cách bằng khoảng trắng:
>` int x; // int và x phải được phân cách bằng khoảng trắng`

    Nếu chúng ta viết `intx` thay thế, trình biên dịch sẽ hiểu đây là một định danh và sau đó báo cáo lại rằng nó không biết định danh `intx` là gì.
- Một ví dụ khác, kiểu trả về và tên của hàm phải được phân cách bằng khoảng trắng:
>`int main(); // int và main() phải được phân cách bằng khoảng trắng`

**Lưu ý về khoảng trắng:**

- Khi khoảng trắng có nhiệm vụ như một dấu phân cách, trình biên dịch không quan tâm đến việc sử dụng bao nhiêu khoảng trắng, miễn là có một khoảng trắng nào đó.
- Các định nghĩa biến sau đều hợp lệ:

>```
>int x;
>int                y;
>            int
>z;
>```

### 2. **Xuống dòng (Newline) như dấu phân cách:**

Trong một số trường hợp, xuống dòng được sử dụng như một dấu phân cách. Inline comment được kết thúc bằng một xuống dòng.

**Ví dụ:** Việc thực hiện điều này sẽ khiến bạn gặp rắc rối:
>```
>std::cout << "Hello world!"; // Đây là một phần của comment và
Đây không phải là một phần của comment
>```

### 3. **Định dạng code:**

Khoảng trắng cũng được sử dụng để cải thiện khả năng đọc của code. Mặc dù trình biên dịch không quan tâm đến việc bạn sử dụng bao nhiêu khoảng trắng để thụt lề hoặc giãn cách các dòng, việc sử dụng chúng hợp lý sẽ giúp code dễ hiểu hơn.


**Ví dụ: đoạn code sau khó đọc**
>```
>#include <iostream>
>int main(){std::cout<<"Hello world";return 0;}
>```

**Đoạn code sau dễ đọc hơn (nhưng vẫn hơi dày đặc):**
>```
>#include <iostream>
>int main() {
>std::cout << "Hello world";
>return 0;
>}
>```

**Ví dụ về code được định dạng tốt:**
>```
>#include <iostream>
>#include <string>
>
>int main() {
>    std::cout << "Hello, world!" << std::endl;
>    return 0;
>}
>```

**Ngắt dòng cho các câu lệnh (statement):** Các câu lệnh (statement) có thể được ngắt ra nhiều dòng nếu cần.
>```
>#include <iostream>
>
>int main() {
>    std::cout
>        << "Hello world"; // Vẫn hoạt động bình thường
>    return 0;
>}
>```

Điều này hữu ích cho các câu lệnh đặc biệt dài.

### **Văn bản được trích dẫn và Khoảng trắng trong Chuỗi (Quoted text and Whitespace in Strings)**

Văn bản được trích dẫn (**Quoted text**) là một chuỗi ký tự được bao bọc trong dấu nháy kép (`"`). Số lượng khoảng trắng bên trong văn bản được trích dẫn sẽ được hiểu theo đúng nghĩa đen.

>`std::cout << "Hello world!"; // In ra "Hello world!" (không có khoảng trắng thừa)`

Khác với:
>`std::cout << "Hello          world!"; // In ra "Hello          world!" (in cả 8 khoảng trắng)
`

**Lưu ý:**
- Không được phép có xuống dòng (newline) bên trong văn bản được trích dẫn.

>`std::cout << "Hello  // Không được phép!`\
>`     world!";`
- Các đoạn văn bản được trích dẫn được phân cách chỉ bằng khoảng trắng (dấu cách, tab hoặc xuống dòng) sẽ được nối lại với nhau.

>`std::cout << "Hello "  // Nối "Hello "`\
>`          "world!";  // với "world!"`\
>`// In ra "Hello world!"`


### **Định dạng cơ bản trong C++**

**Không giống như một số ngôn ngữ khác, C++ không áp đặt bất kỳ hạn chế định dạng nào cho người lập trình.** Vì lý do này, chúng ta nói rằng C++ là ngôn ngữ **không phụ thuộc vào khoảng trắng** (**whitespace-independent**).

Đây là một lợi thế nhưng cũng là bất lợi. Một mặt, thật tuyệt vời khi có thể thoải mái làm bất cứ điều gì bạn muốn. Mặt khác, nhiều phương pháp định dạng chương trình C++ khác nhau đã được phát triển trong nhiều năm và bạn sẽ thấy (đôi khi là sự bất đồng đáng kể và gây mất tập trung) về phương pháp nào là tốt nhất. Nguyên tắc cơ bản của chúng tôi là các kiểu cách tốt nhất là những kiểu cách tạo ra code dễ đọc nhất và cung cấp sự nhất quán cao nhất.

**Dưới đây là các khuyến nghị của chúng tôi về định dạng cơ bản:**
1. <u>Thụt lề (indentation) hay dấu cách (space):</u>
- Bạn có thể sử dụng tab hoặc dấu cách để thụt lề (phần lớn các IDE đều có cài đặt cho phép bạn chuyển đổi một lần nhấn tab thành số lượng khoảng trắng thích hợp).
- Các nhà phát triển thích sử dụng khoảng trắng có xu hướng làm như vậy bởi vì nó đảm bảo rằng code được căn chỉnh chính xác theo ý định bất kể sử dụng trình soạn thảo hoặc cài đặt nào. Những người ủng hộ việc sử dụng tab tự hỏi tại sao bạn không sử dụng ký tự được thiết kế để thụt lề cho việc thụt lề, đặc biệt là vì bạn có thể đặt độ rộng thành bất kỳ tùy chọn cá nhân nào của bạn. Không có câu trả lời đúng ở đây - và tranh luận về nó giống như tranh luận về việc bánh ngọt hay bánh nướng là ngon hơn. Cuối cùng nó phụ thuộc vào sở thích cá nhân.
- Dù bằng cách nào, chúng tôi khuyên bạn nên đặt tab của mình thành thụt lề bằng 4 dấu cách. Một số IDE mặc định thành thụt lề 3 dấu cách, điều này cũng ổn.

2. <u>Ngoặc nhọn trong hàm (Function braces):</u>
- Có hai kiểu cách thông thường cho ngoặc nhọn trong hàm.
- Nhiều nhà phát triển thích đặt ngoặc nhọn mở trên cùng dòng với câu lệnh:
>```
>int main() {
>    // Các câu lệnh ở đây
>}
>```

Lý do cho điều này là nó làm giảm lượng khoảng trắng theo chiều dọc (vì bạn không dành toàn bộ một dòng cho một ngoặc nhọn mở), do đó bạn có thể chứa nhiều code hơn trên một màn hình. Điều này cải thiện khả năng hiểu code, vì bạn không cần phải cuộn nhiều để hiểu code đang làm gì.

Tuy nhiên, trong loạt bài hướng dẫn này, chúng tôi sẽ sử dụng cách thay thế phổ biến, trong đó ngoặc nhọn mở xuất hiện trên dòng riêng của nó:
>```
>int main()
>{
>    // Các câu lệnh ở đây
>}
>```

Điều này cải thiện khả năng đọc và ít lỗi hơn vì các cặp ngoặc nhọn của bạn luôn được thụt lề ở cùng một cấp độ. Nếu bạn gặp lỗi trình biên dịch do không khớp ngoặc nhọn, bạn sẽ rất dễ dàng xác định vị trí.

3. <u>Thụt lề cho các câu lệnh (Statement indentation):</u>
- Mỗi câu lệnh trong ngoặc nhọn nên bắt đầu thụt lề một tab tính từ ngoặc nhọn mở của hàm mà nó thuộc về. Ví dụ:
>```
>int main()
>{
>    std::cout << "Hello world!\n"; // thụt lề một tab (4 khoảng trắng)
>    std::cout << "Nice to meet you.\n"; // thụt lề một tab (4 khoảng trắng)
>}
>```

4. <u>Độ dài dòng (Line length):</u>
- Dòng không nên quá dài. Theo thông lệ, 80 ký tự là tiêu chuẩn thực tế cho độ dài tối đa của một dòng.
- Nếu một dòng vượt quá 80 ký tự:
    - Chia nhỏ dòng đó: Bạn nên tách dòng đó thành nhiều dòng nhỏ hơn (ở những vị trí thích hợp).
    - Thụt lề cho các dòng tiếp theo: Mỗi dòng được tách ra nên được thụt lề thêm một tab so với dòng gốc.
    - Căn chỉnh với dòng trên (tùy chọn): Nếu các dòng được tách ra có nội dung tương tự nhau, bạn có thể căn chỉnh chúng với dòng trên để cải thiện khả năng đọc. Chọn cách nào dễ đọc hơn thì cứ dùng cách đó.


>```
>int main()
>{
>    std::cout << "This is a really, really, really, really, really, really, really, "
>        "really long line\n"; // thụt lề thêm một lần cho dòng tiếp theo
>
>    std::cout << "This is another really, really, really, really, really, really, really, "
>                 "really long line\n"; // dòng tiếp theo được căn lề bằng với dòng ở trên
>
>    std::cout << "This one is short\n";
>} 
>```

>**Thực tiễn:**
Luôn cân nhắc giữ cho các dòng code của bạn có độ dài 80 ký tự trở xuống.

>**Mẹo:**\
>Nhiều trình soạn thảo code có một tính năng tích hợp sẵn (hoặc plugin/extension) giúp hiển thị một đường thẳng (được gọi là "đường dẫn cột" - column guide) ở một cột nhất định (ví dụ: ở ký tự thứ 80), để bạn có thể dễ dàng xem  khi nào các dòng code của bạn trở nên quá dài.
Để biết trình soạn thảo của bạn có hỗ trợ tính năng này không, hãy tìm kiếm trên **Google** bằng cú pháp `"[Tên trình soạn thảo của bạn] + Column guide".`

5. <u>Phân chia dòng với toán tử</u>
- Nếu một dòng dài được phân chia với một toán tử (ví dụ như `<<` hoặc `+`), toán tử đó nên được đặt ở đầu dòng tiếp theo.
- **Ví dụ:**
>```
>std::cout << 3 + 4
>    + 5 + 6
>    * 7 * 8;
>```
- Điều này giúp làm rõ ràng hơn rằng các dòng tiếp theo là phần tiếp nối của các dòng trước đó và cho phép bạn căn chỉnh các toán tử ở bên trái, giúp việc đọc dễ dàng hơn.
6. <u>Sử dụng khoảng trắng để cải thiện khả năng đọc:</u>
- Sử dụng khoảng trắng để làm cho code của bạn dễ đọc hơn bằng cách căn chỉnh các giá trị, bình luận hoặc thêm khoảng cách giữa các khối code.
- **Khó đọc:**

>```
>cost = 57;
>pricePerItem = 24;
>value = 5;
>numberOfItems = 17;
>```

- **Dễ đọc**
    
>```
>cost          = 57;
>pricePerItem  = 24;
>value         = 5;
>numberOfItems = 17;
>```

- **Khó đọc:**

>```
>std::cout << "Hello world!\n"; // cout lives in the iostream library
>std::cout << "It is very nice to meet you!\n"; // these comments make the code hard to read
>std::cout << "Yeah!\n"; // especially when lines are different lengths
>```
- **Dễ học:**

>```
>std::cout << "Hello world!\n";                  // cout lives in the iostream library
>std::cout << "It is very nice to meet you!\n";  // these comments are easier to read
>std::cout << "Yeah!\n";                         // especially when all lined up
>```

- **Khó đọc:**

>```
>// cout lives in the iostream library
>std::cout << "Hello world!\n";
>// these comments make the code hard to read
>std::cout << "It is very nice to meet you!\n";
>// especially when all bunched together
>std::cout << "Yeah!\n";
>```
- **Dễ đọc:**

>```
>// cout lives in the iostream library
>std::cout << "Hello world!\n";
>
>// these comments are easier to read
>std::cout << "It is very nice to meet you!\n";
>
>// when separated by whitespace
>std::cout << "Yeah!\n";
>```

Trong suốt hướng dẫn này, chúng tôi sẽ tuân theo các quy ước này và chúng sẽ trở thành bản năng thứ hai của bạn. Khi giới thiệu các chủ đề mới với bạn, chúng tôi sẽ giới thiệu các đề xuất về kiểu cách mới để đi kèm với các tính năng đó.

Cuối cùng, C++ cung cấp cho bạn sức mạnh để lựa chọn bất kỳ kiểu cách nào mà bạn cảm thấy thoải mái nhất hoặc cho là tốt nhất. Tuy nhiên, chúng tôi đặc biệt khuyên bạn nên sử dụng cùng kiểu cách mà chúng tôi sử dụng cho các ví dụ của mình. Nó đã được hàng nghìn lập trình viên kiểm tra thực tế trên hàng tỷ dòng code và được tối ưu hóa để thành công.

**Một ngoại lệ:** Nếu bạn đang làm việc trên codebase của người khác, hãy áp dụng phong cách của họ. Tốt hơn nên ưu tiên sự nhất quán hơn sở thích của bạn.

**Style guide:** là một tài liệu ngắn gọn, thể hiện quan điểm chứa các quy ước lập trình (đôi khi tùy ý), hướng dẫn định dạng và các thực hành tốt nhất. Mục tiêu của một style guide là đảm bảo rằng tất cả các nhà phát triển trong một dự án đều lập trình theo một cách thống nhất.

Một số style guide C++ được tham khảo phổ biến bao gồm:

[C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) - Được bảo trì bởi Bjarne Stroustrup và Herb Sutter.<br>
[Google](https://google.github.io/styleguide/cppguide.html)<br>
[LLVM](https://llvm.org/docs/CodingStandards.html)<br>
[GCC/GNU](https://gcc.gnu.org/codingconventions.html)<br>
Nhìn chung, chúng tôi ưu tiên C++ Core Guidelines vì chúng cập nhật và được áp dụng rộng rãi.


## **Bài 1.9: <u>Giới thiệu về Literal và Toán tử</u>**

### **Literal (Giá trị nguyên văn)**:

Hãy xem xét hai câu lệnh sau:

>`std::cout << "Hello world!";`\
>`int x { 5 };`

`"Hello world!"` và `5` là gì? Chúng là **literal** (giá trị nguyên văn). **Literal** (giá trị nguyên văn) là một giá trị cố định được đưa trực tiếp vào mã nguồn. **Literal** và **biến** đều có một giá trị (và một kiểu dữ liệu). Khác với biến (có giá trị có thể được thiết lập và thay đổi thông qua khởi tạo và gán tương ứng), giá trị của **literal** là **cố định** (`5` luôn luôn là `5`). Đây là lý do tại sao **literal** được gọi là hằng giá trị.

Để làm nổi bật hơn sự khác biệt giữa literal và biến, chúng ta hãy xem xét chương trình ngắn này:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << 5 << '\n'; // in ra giá trị của một literal
>
>    int x { 5 };
>    std::cout << x << '\n'; // in ra giá trị của một biến
>    return 0;
>}
>```

Ở dòng 5, chúng ta đang in giá trị `5` ra console. Khi trình biên dịch biên dịch đoạn này, nó sẽ tạo ra code khiến `std::cout` in ra giá trị `5`. Giá trị `5` này được biên dịch vào trong file thực thi và có thể được sử dụng trực tiếp.

Ở dòng 7, chúng ta đang tạo một biến tên `x` và khởi tạo nó với giá trị `5`. Trình biên dịch sẽ tạo ra code sao chép giá trị literal `5` vào bất kỳ vị trí bộ nhớ nào được cấp cho `x`. Ở dòng 8, khi chúng ta in `x`, trình biên dịch sẽ tạo ra code khiến `std::cout` in ra giá trị tại vị trí bộ nhớ của x (có giá trị là `5`).

Do đó, cả hai câu lệnh in đều thực hiện cùng một tác vụ (in ra giá trị `5`). Nhưng trong trường hợp của literal, giá trị `5` được in ra trực tiếp. Trong trường hợp của biến, giá trị `5` phải được lấy từ bộ nhớ mà biến đó biểu diễn.

Điều này cũng giải thích tại sao literal là hằng giá trị trong khi biến có thể thay đổi. Giá trị của literal được đặt trực tiếp vào file thực thi và bản thân file thực thi không thể thay đổi sau khi được tạo. Giá trị của biến được đặt trong bộ nhớ và giá trị của bộ nhớ có thể thay đổi trong khi file thực thi đang chạy.

>**Lưu ý quan trọng:**
>- Literal là các giá trị được đưa trực tiếp vào mã nguồn. Các giá trị này thường xuất hiện trực tiếp trong code thực thi (trừ khi chúng được tối ưu hóa).
>- Đối tượng và biến đại diện cho các vị trí bộ nhớ chứa các giá trị. Các giá trị này có thể được truy xuất theo yêu cầu.

>**Nội dung liên quan:**
>Chúng ta sẽ tìm hiểu sâu hơn về literal trong bài 5.2 -- Literal.



### **Toán tử trong C++**

#### <u>Toán tử</u>



Trong toán học, một **phép toán (operation)** là một phép thực hiện tính toán liên quan đến 0 hoặc nhiều giá trị đầu vào (gọi là **toán hạng - operands**) tạo ra một giá trị mới (gọi là **giá trị đầu ra - output value**). Phép toán cụ thể cần thực hiện được biểu thị bằng một ký hiệu gọi là **toán tử** (operator).

Ví dụ: từ nhỏ chúng ta đều học được rằng 2 + 3 bằng 5. Trong trường hợp này, các literal 2 và 3 là toán hạng và ký hiệu + là toán tử cho biết chúng ta cần thực hiện phép cộng toán học trên các toán hạng để tạo ra giá trị mới 5.





#### <u>Toán tử trong C++</u>

Trong C++, các phép toán cũng hoạt động tương tự như vậy. Ví dụ:
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << 1 + 2 << '\n';
>
>    return 0;
>}
>```

Trong chương trình này, các literal `1` và `2` là toán hạng cho toán tử cộng (`+`), toán tử này tạo ra giá trị đầu ra `3`. Giá trị đầu ra này sau đó được in ra console. Trong C++, giá trị đầu ra của một phép toán thường được gọi là **giá trị trả về (return value).**

Bạn có thể đã khá quen thuộc với các toán tử số học tiêu chuẩn thường được sử dụng trong toán học, bao gồm cộng (`+`), trừ (`-`), nhân (`*`), và chia (`/`). Trong C++, gán (`=`) cũng là một toán tử, cũng như toán tử đưa vào (`<<`), trích xuất (`>>`) và so sánh bằng (`==`). Trong khi hầu hết các toán tử có biểu tượng làm tên (ví dụ: `+`, hoặc `==`), thì cũng có một số toán tử là từ khóa (ví dụ: `new`, `delete` và `throw`).

**Số lượng toán hạng**

Số lượng toán hạng mà một toán tử lấy làm đầu vào được gọi là **arity** (ngôi) của toán tử. Ít người biết từ này có nghĩa là gì, vì vậy đừng sử dụng nó trong cuộc trò chuyện và mong đợi mọi người hiểu bạn đang nói về điều gì. Toán tử trong C++ có bốn loại arity khác nhau:
- **Một ngôi (Unary)**: Toán tử một ngôi tác động lên một toán hạng. Ví dụ về toán tử một ngôi là toán tử `-`. Ví dụ, với `-5`, toán tử `-` lấy toán hạng theo nghĩa đen `5` và đảo ngược dấu của nó để tạo ra giá trị đầu ra mới `-5`.
- **Hai ngôi (Binary)**: Toán tử hai ngôi tác động lên hai toán hạng (thường được gọi là trái và phải, vì toán hạng trái xuất hiện ở bên trái của toán tử và toán hạng phải xuất hiện ở bên phải của toán tử). Ví dụ về toán tử hai ngôi là toán tử `+`. Ví dụ, với `3 + 4`, toán tử + lấy toán hạng trái `3` và toán hạng phải `4` và áp dụng phép cộng toán học để tạo ra giá trị đầu ra mới `7`. Toán tử chèn (`<<`) và trích xuất (`>>`) là các toán tử hai ngôi, lấy `std::cout` hoặc `std::cin` ở bên trái và giá trị cần xuất ra hoặc biến để nhập vào ở bên phải.
- **Ba ngôi (Ternary)**: Toán tử ba ngôi tác động lên ba toán hạng. Chỉ có một toán tử này trong C++ (toán tử điều kiện), chúng ta sẽ tìm hiểu sau.
- **Không ngôi (Nullary)**: Toán tử không ngôi tác động lên 0 toán hạng. Cũng chỉ có một toán tử này trong C++ (toán tử `throw`), chúng ta cũng sẽ tìm hiểu sau.

Lưu ý rằng một số toán tử có nhiều hơn một nghĩa tùy thuộc vào cách chúng được sử dụng. Ví dụ, toán tử `-` có hai ngữ cảnh. Nó có thể được sử dụng ở dạng một ngôi để đảo ngược dấu của một số (ví dụ: để chuyển đổi `5` thành `-5` hoặc ngược lại), hoặc nó có thể được sử dụng ở dạng hai ngôi để thực hiện phép trừ (ví dụ: `4 - 3`).







### **Liên kết toán tử**

Các toán tử có thể được liên kết với nhau sao cho kết quả đầu ra của một toán tử có thể được sử dụng làm đầu vào cho một toán tử khác. Ví dụ, với biểu thức: `2 * 3 + 4`, toán tử nhân được thực hiện trước tiên, và chuyển đổi toán hạng trái `2` và toán hạng phải `3` thành giá trị trả về `6` (trở thành toán hạng trái cho toán tử cộng). Tiếp theo, toán tử cộng được thực hiện, và chuyển đổi toán hạng trái `6` và toán hạng phải `4` thành giá trị mới `10`.

Chúng ta sẽ nói thêm về thứ tự thực thi các toán tử khi chúng ta đi sâu vào chủ đề toán tử. Hiện tại, chỉ cần biết rằng các toán tử số học được thực hiện theo cùng thứ tự như trong toán học chuẩn: **Đầu tiên là dấu ngoặc, tiếp theo là lũy thừa, sau đó là nhân và chia, sau đó là cộng và trừ**. Thứ tự này đôi khi được viết tắt là **PEMDAS**, hoặc được mở rộng thành cụm từ **“Please Excuse My Dear Aunt Sally”** (Vui lòng tha lỗi cho dì Sally thân mến của tôi).





### **Giá trị trả về và tác dụng phụ**

Hầu hết các toán tử trong C++ chỉ sử dụng toán hạng của chúng để tính toán một giá trị trả về. <br>
Ví dụ, `-5` tạo ra giá trị trả về `-5` và `2 + 3` tạo ra giá trị trả về `5`. Có một vài toán tử không tạo ra giá trị trả về (chẳng hạn như `delete` và `throw`). Chúng ta sẽ đề cập đến những điều này sau.

Một số toán tử có các hành vi bổ sung. Một toán tử (hoặc hàm) có một số tác động quan sát được vượt ra ngoài việc tạo ra giá trị trả về được gọi là có **tác dụng phụ** (hay **hiệu ứng lề**) (**side effect**). Ví dụ, khi `x = 5` được đánh giá, toán tử gán có tác dụng phụ là gán giá trị `5` cho biến `x`. Giá trị thay đổi của `x` có thể quan sát được (ví dụ: bằng cách in giá trị của `x`) ngay cả sau khi toán tử thực hiện xong. `std::cout << 5` có tác dụng phụ là in `5` ra console. Chúng ta có thể quan sát thấy thực tế là `5` đã được in ra console ngay cả sau khi `std::cout << 5` đã thực hiện xong.

Các toán tử có tác dụng phụ thường được gọi vì hành vi của tác dụng phụ chứ không phải vì giá trị trả về (nếu có) mà các toán tử đó tạo ra.

>**Thuật ngữ** <br>
>Trong ngôn ngữ thông dụng, thuật ngữ **“tác dụng phụ”** thường được sử dụng để chỉ một kết quả phụ (thường là tiêu cực hoặc không mong đợi) của một điều gì đó khác xảy ra (chẳng hạn như dùng thuốc). Ví dụ, một tác dụng phụ phổ biến của việc uống kháng sinh đường uống là tiêu chảy. Như vậy, chúng ta thường nghĩ về tác dụng phụ như những thứ chúng ta muốn tránh, hoặc những thứ không liên quan đến mục tiêu chính.
>
>Trong C++, thuật ngữ **“tác dụng phụ”** có một ý nghĩa khác: nó là một tác động quan sát được của một toán tử hoặc hàm vượt ra ngoài việc tạo ra giá trị trả về.
>
>Vì phép gán có tác dụng quan sát được là thay đổi giá trị của một đối tượng, nên đây được coi là một tác dụng phụ. Chúng ta sử dụng một số toán tử nhất định (ví dụ: toán tử gán) chủ yếu vì các tác dụng phụ của chúng. Trong những trường hợp như vậy, tác dụng phụ vừa có lợi vừa có thể dự đoán được (và giá trị trả về thường là thứ không cần thiết).

>**Đối với người đọc nâng cao** <br>
>Đối với các toán tử mà chúng ta gọi chủ yếu để lấy giá trị trả về của chúng (ví dụ: toán tử `+` hoặc toán tử `*`), thì giá trị trả về của chúng thường là rõ ràng (ví dụ: tổng hoặc tích của các toán hạng).
>
>Đối với các toán tử mà chúng ta gọi chủ yếu vì các tác dụng phụ của chúng (ví dụ: toán tử `=` hay toán tử `<<`), thì không phải lúc nào cũng rõ ràng giá trị trả về của chúng là gì (nếu có). Ví dụ, bạn mong đợi giá trị trả về của `x = 5` là gì?
>
>Cả toán tử `=` và toán tử `<<` (khi được sử dụng để xuất giá trị ra console) đều trả về toán hạng trái của chúng. Do đó, `x = 5` trả về `x` và `std::cout << 5` trả về `std::cout`. Điều này được thực hiện để các toán tử này có thể được **liên kết** (**chaining**).
>
>Ví dụ, biểu thức `x = y = 5` được tính toán như `x = (y = 5)`. Đầu tiên `y = 5` gán giá trị `5` cho biến `y`. Sau đó phép toán này trả về giá trị của `y`, giá trị này sau đó có thể được gán cho biến `x`.
>
>Biểu thức `std::cout << "Hello " << "world"` được tính toán như `(std::cout << "Hello ") << "world!"`. Đầu tiên, nó in `"Hello "` ra console. Phép toán này trả về `std::cout`, sau đó nó có thể được sử dụng để in `"world!"` ra console.
>
>Chúng ta sẽ thảo luận thêm về thứ tự thực thi các toán tử trong bài **6.1 - Ưu tiên toán tử và tính kết hợp (Operator precedence and associativity).**

## **Bài 1.10: <u>Giới thiệu về Biểu thức</u>**

### **Biểu thức**

Xét loạt các câu lệnh sau:

>```
>// five() là một hàm trả về giá trị 5
>int five()
>{
>    return 5;
>}
>
>int main()
>{
>    int a{ 2 };             // Khởi tạo biến a với giá trị nguyên văn 2
>    int b{ 2 + 3 };         // Khởi tạo biến b với giá trị được tính toán 5
>    int c{ (2 * 3) + 4 };   // Khởi tạo biến c với giá trị được tính toán 10
>    int d{ b };             // Khởi tạo biến d với giá trị của biến 5
>    int e{ five() };        // Khởi tạo biến e với giá trị trả về của hàm 5
>
>    return 0;
>}
>```

Mỗi câu lệnh này đều định nghĩa một biến mới và khởi tạo nó với một giá trị. Lưu ý rằng các trình khởi tạo được hiển thị ở trên sử dụng nhiều cấu trúc khác nhau: **literal** (giá trị nguyên văn), **biến**, **toán tử** và **lời gọi hàm**. Bằng cách nào đó, C++ chuyển đổi tất cả những thứ khác nhau này thành một giá trị duy nhất sau đó có thể được sử dụng làm giá trị khởi tạo cho biến.

Tất cả các trình khởi tạo này có điểm gì chung? Chúng đều sử dụng một **biểu thức**.

**Biểu thức (expression)** là một dãy các literal, biến, toán tử và lời gọi hàm tính toán một giá trị đơn. Quá trình thực thi biểu thức được gọi là **đánh giá (evaluation)**, và giá trị đơn được tạo ra được gọi là **kết quả (result) của biểu thức**.



>**Nội dung liên quan**
>
>Mặc dù hầu hết các biểu thức được sử dụng để tính toán một giá trị, biểu thức cũng có thể xác định một đối tượng (có thể được đánh giá để lấy giá trị do đối tượng đó giữ) hoặc một hàm (có thể được gọi để lấy giá trị do hàm đó trả về). Chúng tôi sẽ thảo luận thêm về điều này trong **bài 12.2 - Loại giá trị (lvalue và rvalue).**
>
>Hiện tại, chúng ta sẽ giả sử tất cả các biểu thức đều tính toán các giá trị.

Khi một biểu thức được đánh giá, mỗi toán hạng bên trong biểu thức được đánh giá, cho đến khi chỉ còn lại một giá trị duy nhất. Dưới đây là một số ví dụ về các loại biểu thức khác nhau, với chú thích cho biết cách chúng được đánh giá:

* `2 // 2 là một literal được đánh giá thành giá trị 2`
* `"Hello world!" // "Hello world!" là một literal được đánh giá thành chuỗi "Hello world!"`
* `x // x là một biến được đánh giá thành giá trị của x`
* `2 + 3 // toán tử + sử dụng toán hạng 2 và 3 để đánh giá thành giá trị 5`
* `five() // được đánh giá thành giá trị trả về của hàm five()`

Như bạn có thể thấy, các literal được đánh giá thành giá trị riêng của chúng. Biến được đánh giá thành giá trị của biến. Toán tử (chẳng hạn như toán tử `+`) sử dụng toán hạng của chúng để đánh giá thành một giá trị khác. Chúng ta chưa đề cập đến các lời gọi hàm, nhưng trong ngữ cảnh của một biểu thức, các lời gọi hàm được đánh giá thành bất kỳ giá trị nào mà hàm trả về.

Biểu thức liên quan đến toán tử có tác dụng phụ phức tạp hơn một chút:

- `x = 5 // x = 5 có tác dụng phụ là gán 5 cho x, được đánh giá thành x`
- `x = 2 + 3 // có tác dụng phụ là gán 5 cho x, được đánh giá thành x`
- `std::cout << x // có tác dụng phụ là in giá trị của x ra console, được đánh giá thành std::cout`

Lưu ý rằng biểu thức không kết thúc bằng dấu chấm phẩy và không thể được biên dịch riêng lẻ. Ví dụ, nếu bạn cố gắng biên dịch biểu thức `x = 5`, trình biên dịch của bạn sẽ phàn nàn (có thể là về việc thiếu dấu chấm phẩy). Thay vào đó, các biểu thức luôn được đánh giá như một phần của các câu lệnh.

Ví dụ, hãy xem xét câu lệnh này:

>`int x{ 2 + 3 }; // 2 + 3 là một biểu thức không có dấu chấm phẩy - dấu chấm phẩy nằm ở cuối câu lệnh chứa biểu thức`

Nếu bạn phân tích cú pháp của câu lệnh này, nó sẽ trông như thế này

>`type identifier { expression };`


>**Lưu ý quan trọng**
>
>Bất cứ nơi nào bạn có thể sử dụng một giá trị đơn lẻ trong C++, bạn cũng có thể sử dụng một biểu thức tạo ra giá trị thay thế, và biểu thức đó sẽ được đánh giá để tạo ra một giá trị đơn.



### **Các câu lệnh biểu thức (Expression statements)**

Một số biểu thức nhất định (chẳng hạn như `x = 5`) hữu ích vì các tác dụng phụ của chúng (trong trường hợp này, là để gán giá trị `5` cho biến `x`). Tuy nhiên, như đã đề cập ở trên, các biểu thức không thể được thực thi riêng lẻ - chúng phải tồn tại như một phần của một câu lệnh. Vậy làm thế nào để chúng ta có thể sử dụng các biểu thức như vậy?

May mắn thay, việc chuyển đổi bất kỳ biểu thức nào thành một câu lệnh tương đương là rất dễ dàng. Một **câu lệnh biểu thức (expression statement)** là một câu lệnh bao gồm một biểu thức theo sau dấu chấm phẩy. Khi câu lệnh biểu thức được thực thi, biểu thức sẽ được đánh giá.

Do đó, chúng ta có thể lấy bất kỳ biểu thức nào (chẳng hạn như `x = 5`) và biến nó thành một câu lệnh biểu thức (`x = 5;`) có thể được biên dịch.

Khi một biểu thức được sử dụng trong một câu lệnh biểu thức, bất kỳ giá trị trả về nào do biểu thức tạo ra sẽ bị loại bỏ (vì nó không được sử dụng).



### **Các câu lệnh biểu thức vô dụng (Useless expression statements)**

Chúng ta cũng có thể tạo các câu lệnh biểu thức có thể biên dịch nhưng không có tác dụng gì. Ví dụ, câu lệnh biểu thức (`2 * 3;`) là một câu lệnh biểu thức có biểu thức được đánh giá thành giá trị kết quả là `6`, sau đó giá trị này bị loại bỏ. Mặc dù hợp lệ về cú pháp, các câu lệnh biểu thức như vậy là vô dụng. Một số trình biên dịch (chẳng hạn như **gcc** và **Clang**) sẽ tạo ra cảnh báo nếu chúng có thể phát hiện ra một câu lệnh biểu thức là vô dụng.

### **Các biểu thức con (Subexpressions), biểu thức đầy đủ (Full expressions) và biểu thức ghép (Compound expressions)**

Đôi khi chúng ta cần đề cập đến các loại biểu thức cụ thể. Vì mục đích này, chúng ta sẽ định nghĩa một số thuật ngữ liên quan.

Xem xét các biểu thức sau:

* `2 // 2 là một literal được đánh giá thành giá trị 2`
* `2 + 3 // 2 + 3 sử dụng toán tử + để đánh giá thành giá trị 5`
* `x = 4 + 5 // 4 + 5 được đánh giá thành giá trị 9, sau đó được gán cho biến x`
Nói một cách đơn giản hơn, một **biểu thức con (subexpression)** là một biểu thức được sử dụng như một toán hạng. Ví dụ, các biểu con của `x = 4 + 5` là `x` và `4 + 5`. Các biểu con của `4 + 5` là `4` và `5`.

**Biểu thức đầy đủ (full expression)** là một biểu thức không phải là biểu con. Cả ba biểu thức ở trên (`2`, `2 + 3` và `x = 4 + 5`) đều là biểu thức đầy đủ.

Trong ngôn ngữ thông thường, một **biểu thức ghép (compound expression)** là một biểu thức chứa hai hoặc nhiều toán tử. `x = 4 + 5` là một **biểu thức ghép** vì nó chứa hai phép toán (toán tử gán `=` và toán tử cộng `+`). `2` và `2 + 3` không phải là biểu thức ghép.

## **Bài 1.11: <u>Phát triển chương trình đầu tiên của bạn</u>**

### **Giới thiệu**

Các bài học trước đã giới thiệu rất nhiều thuật ngữ và khái niệm mà chúng ta sẽ sử dụng trong hầu hết mọi chương trình được tạo. Trong bài học này, chúng ta sẽ hướng dẫn bạn từng bước về quá trình tích hợp các kiến thức này vào chương trình đơn giản đầu tiên của mình.

### **"Nhân đôi"**

Trước tiên, hãy tạo một chương trình yêu cầu người dùng nhập một số nguyên, đợi người dùng nhập số nguyên, sau đó thông báo cho họ biết kết quả của phép nhân `2` với số đó. Chương trình sẽ tạo ra đầu ra sau (giả sử tôi nhập `4`):
>`Enter an integer: 4`
>`Double that number is: 8`

Chúng ta sẽ giải quyết bài toán này như thế nào? Theo từng bước.

>**Thực hành tốt**
>
>Lập trình viên mới thường cố gắng viết toàn bộ chương trình cùng một lúc, sau đó sẽ bị choáng ngợp khi gặp nhiều lỗi. Chiến lược tốt hơn là thêm từng phần một, đảm bảo nó có thể biên dịch và kiểm tra nó. Sau đó, khi bạn chắc chắn nó hoạt động, hãy chuyển sang phần tiếp theo.

Chúng ta sẽ áp dụng chiến lược đó ở đây. Khi chúng ta thực hiện từng bước, hãy gõ (không sao chép/dán) từng chương trình vào trình soạn thảo mã của bạn, biên dịch và chạy nó.

Đầu tiên, ta sẽ tạo một dự án mới.

Bây giờ chúng ta hãy bắt đầu với một số bộ khung cơ bản. Chúng ta biết mình sẽ cần một hàm `main()` (vì tất cả các chương trình C++ đều phải có một hàm), vì vậy nếu IDE của bạn không tạo ra một hàm trống khi bạn tạo một dự án mới, hãy tạo một hàm:

>```
>int main()
>{
>    return 0;
>}
>```

Chúng ta biết mình sẽ cần xuất văn bản ra console và lấy văn bản từ bàn phím của người dùng, vì vậy chúng ta cần `#include <iostream>` để truy cập vào `std::cout` và `std::cin`.

>```
>#include <iostream>
>
>int main()
>{
>    return 0;
>}
>```

Bây giờ hãy thông báo cho người dùng rằng chúng ta cần họ nhập một số nguyên:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    return 0;
>}
>```

Lúc này, chương trình của bạn sẽ tạo ra kết quả này:

>`Enter an integer:`

và sau đó kết thúc.



Tiếp theo, chúng ta sẽ lấy đầu vào của người dùng. Chúng ta sẽ sử dụng `std::cin` và toán tử `>>` để lấy đầu vào của người dùng. Nhưng chúng ta cũng cần định nghĩa một biến để lưu trữ đầu vào đó để sử dụng sau này.

>```
>#include <iostream>
>
>int main() // Lưu ý: chương trình này có lỗi ở đâu đó
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ }; // Định nghĩa biến num là một biến kiểu số nguyên
>    std::cin >> num; // Lấy giá trị số nguyên từ bàn phím của người dùng
>
>    return 0;
>}
>```

Đã đến lúc biên dịch chương trình của chúng ta, và rồi...<br>
Ố ồ, đây là những gì tác giả nhận được trên Visual Studio 2017

>```
>1>------ Build started: Project: Double, Configuration: Release Win32 ------
>1>Double.cpp
>1>c:\vcprojects\double\double.cpp(8): error C2678: binary '<<': no operator found which takes a left-hand operand of type 'std::istream' (or there is no acceptable conversion)
>1>c:\vcprojects\double\double.cpp: note: could be 'built-in C++ operator<<(bool, int)'
>1>c:\vcprojects\double\double.cpp: note: while trying to match the argument list '(std::istream, int)'
>1>Done building project "Double.vcxproj" -- FAILED.
>========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========
>```

Ôi chao! Chúng ta đã gặp lỗi biên dịch!

Trước tiên, vì chương trình đã biên dịch được trước khi chúng ta thực hiện cập nhật mới nhất này, và bây giờ không biên dịch được nữa, nên lỗi chắc chắn phải nằm trong đoạn mã vừa thêm (dòng 7 và 8). Điều đó giúp giảm đáng kể lượng mã cần kiểm tra để tìm lỗi. Dòng 7 khá đơn giản (chỉ là định nghĩa biến), vì vậy lỗi có thể không nằm ở đó. Điều đó khiến dòng 8 trở thành thủ phạm có khả năng nhất.

Thứ hai, thông báo lỗi này không dễ đọc. Nhưng hãy cùng phân tích một số yếu tố chính: Trình biên dịch đang thông báo cho chúng ta rằng nó gặp lỗi ở dòng 8. Điều đó có nghĩa là lỗi thực sự có thể nằm ở dòng 8 hoặc có thể là dòng trước đó, điều này củng cố đánh giá trước đó của chúng ta. Tiếp theo, trình biên dịch đang thông báo cho bạn rằng nó không thể tìm thấy toán tử '<<' nào có toán hạng bên trái kiểu std::istream (đó là kiểu của std::cin). Nói cách khác, toán tử << không biết phải làm gì với std::cin, vì vậy lỗi có thể nằm ở cách chúng ta sử dụng std::cin hoặc cách chúng ta sử dụng toán tử <<.

Bạn có thấy lỗi chưa? Nếu chưa, hãy dành một chút thời gian và xem liệu bạn có thể tìm thấy nó không.

Đây là chương trình chứa mã đã sửa:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ };
>    std::cin >> num; // std::cin sử dụng toán tử >>, không phải toán tử <<!
>
>    return 0;
>}
>```

Bây giờ chương trình sẽ được biên dịch và chúng ta có thể kiểm tra nó. Chương trình sẽ đợi bạn nhập một số, vì vậy hãy nhập `4`. Đầu ra sẽ trông như thế này:



>`Enter an integer: 4`


Gần xong rồi! Bước cuối cùng là nhân đôi số đó.

Khi hoàn thành bước cuối cùng này, chương trình của chúng ta sẽ biên dịch và chạy thành công, tạo ra đầu ra mong muốn.

Có (ít nhất) 3 cách để chúng ta có thể thực hiện điều này. Hãy cùng đi từ tệ nhất đến tốt nhất.

#### *<u>Giải pháp không tốt:</u>*

>```
>#include <iostream>
>
>// Phiên bản tệ nhất
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ };
>    std::cin >> num;
>
>    num = num * 2; // Nhân đôi giá trị của num, sau đó gán lại giá trị đó cho num
>
>    std::cout << "Double that number is: " << num << '\n';
>
>    return 0;
>}
>```

**Giải thích:**

Trong giải pháp này, chúng ta sử dụng một biểu thức để nhân `num` với `2`, sau đó gán lại giá trị đó cho `num`. Từ thời điểm đó trở đi, `num` sẽ chứa giá trị được nhân đôi của chúng ta.

**Tại sao đây là giải pháp tồi:**

- Mất tính minh bạch: Trước khi thực hiện câu lệnh gán, `num` chứa giá trị nhập vào của người dùng. Sau khi gán, nó chứa một giá trị khác. Điều này gây nhầm lẫn.
- Ghi đè dữ liệu người dùng: Chúng ta ghi đè lên giá trị nhập vào của người dùng bằng cách gán một giá trị mới cho biến `num`. Do đó, nếu sau này chúng ta muốn mở rộng chương trình để thực hiện một thao tác khác với giá trị nhập vào đó (ví dụ: nhân ba giá trị nhập vào của người dùng), thì giá trị đó đã bị mất.

#### *<u>Giải pháp tương đối tốt:</u>*

>```
>#include <iostream>
>
>// Phiên bản ít tệ hơn
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ };
>    std::cin >> num;
>
>    int doublenum{ num * 2 }; // Định nghĩa một biến mới và khởi tạo nó với num * 2
>    std::cout << "Double that number is: " << doublenum << '\n'; // Sau đó in giá trị của biến đó ở đây
>
>    return 0;
>}
>```

**Giải thích:**

Giải pháp này khá dễ đọc và hiểu, đồng thời giải quyết cả hai vấn đề gặp phải trong giải pháp tồi tệ nhất.

**Nhược điểm:**

Nhược điểm chính ở đây là chúng ta đang định nghĩa một biến mới (làm tăng độ phức tạp) để lưu trữ một giá trị mà chúng ta chỉ sử dụng một lần. Chúng ta có thể làm tốt hơn thế.



#### *<u>Giải pháp được ưu tiên</u>*

>```
>#include <iostream>
>
>// Phiên bản được ưu tiên
>int main()
>{
>    std::cout << "Enter an integer: ";
>
>    int num{ };
>    std::cin >> num;
>
>    std::cout << "Double that number is: " <<  num * 2 << '\n'; // Sử dụng biểu thức để nhân num * 2 tại thời điểm chúng ta sẽ in ra nó
>
>    return 0;
>}
>```

**Giải thích:**

Đây là giải pháp được ưu tiên nhất. Khi `std::cout` thực thi, biểu thức `num * 2` sẽ được tính toán và kết quả sẽ là giá trị gấp đôi của `num`. Giá trị đó sẽ được in ra. Bản thân giá trị trong `num` sẽ không bị thay đổi, vì vậy chúng ta có thể sử dụng lại nó sau này nếu muốn.

Phiên bản này là giải pháp tham khảo của chúng tôi.

>**Lưu ý của tác giả**
>
>Mục tiêu đầu tiên và quan trọng nhất của lập trình là khiến chương trình hoạt động. Một chương trình không hoạt động sẽ vô dụng bất kể được viết tốt đến đâu.
>
>Tuy nhiên, có một câu nói mà tôi rất tâm đắc: "Bạn phải viết một chương trình một lần để biết cách bạn nên viết nó ngay từ đầu." Điều này nói lên rằng giải pháp tốt nhất thường không hiển nhiên, và các giải pháp đầu tiên của chúng ta cho các vấn đề thường không tốt như chúng có thể.
>
>Khi chúng ta tập trung vào việc tìm cách để làm cho chương trình hoạt động, thì việc đầu tư nhiều thời gian vào mã mà chúng ta thậm chí không biết có giữ lại không là không hợp lý. Vì vậy, chúng tôi sử dụng các phím tắt. Chúng tôi bỏ qua những thứ như xử lý lỗi và chú thích. Chúng tôi rải mã gỡ lỗi xuyên suốt giải pháp của mình để giúp chúng tôi chẩn đoán các vấn đề và tìm lỗi. Chúng tôi học hỏi khi thực hiện - những thứ chúng tôi nghĩ có thể hoạt động thì hóa ra lại không, và chúng tôi phải quay lại và thử một cách tiếp cận khác.
>
>Kết quả cuối cùng là các giải pháp ban đầu của chúng tôi thường không được cấu trúc tốt, mạnh mẽ (chống lỗi), dễ đọc hoặc ngắn gọn. Vì vậy, một khi chương trình của bạn hoạt động, công việc của bạn thực sự chưa hoàn thành (trừ khi chương trình chỉ sử dụng một lần/bỏ đi). Bước tiếp theo là dọn dẹp mã của bạn. Điều này bao gồm các việc như: xóa (hoặc chú thích) mã tạm thời/gỡ lỗi, thêm chú thích, xử lý các trường hợp lỗi, định dạng mã của bạn và đảm bảo tuân theo các quy trình thực hành tốt nhất. Và thậm chí sau đó, chương trình của bạn có thể không đơn giản như nó có thể - có lẽ có logic trùng lặp có thể được hợp nhất, hoặc nhiều câu lệnh có thể được kết hợp, hoặc các biến không cần thiết, hoặc hàng ngàn điều nhỏ nhặt khác có thể được đơn giản hóa. Quá nhiều lập trình viên mới tập trung vào tối ưu hóa hiệu suất trong khi họ nên tối ưu hóa khả năng bảo trì.
>
>Rất ít giải pháp được trình bày trong các hướng dẫn này có kết quả tuyệt vời ngay từ lần đầu tiên. Thay vào đó, chúng là kết quả của quá trình tinh chỉnh liên tục cho đến khi không thể tìm thấy gì khác để cải thiện. Và trong nhiều trường hợp, người đọc vẫn tìm thấy nhiều điều khác để gợi ý cải tiến!
>
>Tất cả những điều này thực sự để nói: đừng thất vọng nếu/khi các giải pháp của bạn không được tối ưu hóa tuyệt vời ngay từ đầu. Điều đó là bình thường. Hoàn thiện trong lập trình là một quá trình lặp lại (yêu cầu lặp lại nhiều lần).

>**Lưu ý của tác giả**
>
>Một điều nữa: Bạn có thể đang nghĩ, "C++ có quá nhiều quy tắc và khái niệm. Làm thế nào để nhớ tất cả những thứ này?".
>
>Câu trả lời ngắn gọn: Bạn không cần nhớ. C++ là sự kết hợp giữa việc sử dụng những gì bạn đã biết và việc tra cứu cách thực hiện phần còn lại.
>
>Khi bạn đọc trang web này lần đầu tiên, hãy tập trung ít hơn vào việc ghi nhớ các chi tiết cụ thể, mà nhiều hơn vào việc hiểu những gì có thể. Sau đó, khi bạn cần triển khai một cái gì đó trong chương trình bạn đang viết, bạn có thể quay lại đây (hoặc đến một trang web tham khảo) và làm mới lại kiến thức của mình về cách thực hiện.

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

Một biến chưa được gán giá trị được gọi là biến chưa được khởi tạo. Việc cố gắng lấy giá trị của một biến chưa được khởi tạo sẽ dẫn đến **hành vi bất định (undefined behavior)**, có thể biểu hiện theo nhiều cách khác nhau.

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
