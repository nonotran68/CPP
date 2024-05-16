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


