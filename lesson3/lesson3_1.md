## **Bài 3.1: <u>Lỗi cú pháp và lỗi ngữ nghĩa</u>**

Lỗi phần mềm rất phổ biến. Rất dễ mắc phải chúng và khó khăn để tìm ra chúng. Trong chương này, chúng ta sẽ khám phá các chủ đề liên quan đến việc tìm và loại bỏ lỗi trong các chương trình C++ của mình, bao gồm cả việc học cách sử dụng trình gỡ lỗi tích hợp đi kèm với IDE của bạn.

Mặc dù các công cụ và kỹ thuật gỡ lỗi không phải là một phần của tiêu chuẩn C++, việc học cách tìm và loại bỏ lỗi trong các chương trình bạn viết là một phần cực kỳ quan trọng để trở thành một lập trình viên thành công. Do đó, chúng tôi sẽ dành một chút thời gian để đề cập đến các chủ đề như vậy, để khi các chương trình bạn viết trở nên phức tạp hơn, khả năng chẩn đoán và khắc phục sự cố của bạn cũng sẽ tiến triển theo cùng một nhịp độ.

Nếu bạn có kinh nghiệm gỡ lỗi chương trình trong một ngôn ngữ lập trình khác, thì phần lớn nội dung này sẽ quen thuộc với bạn.

### **Lỗi cú pháp và lỗi ngữ nghĩa**

Lập trình có thể đầy thử thách và C++ là một ngôn ngữ hơi lập dị. Kết hợp cả hai điều đó lại, sẽ có rất nhiều cách để mắc lỗi. Lỗi thường thuộc một trong hai loại: lỗi cú pháp và lỗi ngữ nghĩa (lỗi logic).

**Lỗi cú pháp** xảy ra khi bạn viết một câu lệnh không hợp lệ theo ngữ pháp của ngôn ngữ C++. Điều này bao gồm các lỗi như thiếu dấu chấm phẩy, sử dụng các biến chưa được khai báo, dấu ngoặc hoặc ngoặc nhọn không khớp, v.v. Ví dụ, chương trình sau đây chứa một vài lỗi cú pháp:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout < "Hi there"; << x << '\n'; // Toán tử không hợp lệ (<), dấu chấm phẩy thừa, biến chưa được khai báo (x)
>    return 0 // Thiếu dấu chấm phẩy ở cuối câu lệnh
>}
>```

May mắn thay, trình biên dịch thường sẽ bắt được các lỗi cú pháp và tạo ra các cảnh báo hoặc lỗi, vì vậy bạn có thể dễ dàng xác định và khắc phục sự cố. Sau đó, bạn chỉ cần biên dịch lại cho đến khi loại bỏ được tất cả các lỗi.

Khi chương trình của bạn đã được biên dịch chính xác, việc khiến nó thực sự tạo ra kết quả mong muốn có thể khá khó khăn. **Lỗi ngữ nghĩa** xảy ra khi một câu lệnh hợp lệ về cú pháp nhưng không thực hiện những gì lập trình viên định hướng.

Đôi khi chúng sẽ khiến chương trình của bạn bị crash (chết), chẳng hạn như trong trường hợp chia cho `0`:
>```
>#include <iostream>
>
>int main()
>{
>    int a { 10 };
>    int b { 0 };
>    std::cout << a << " / " << b << " = " << a / b << '\n'; // Chia cho 0 là không xác định trong toán học
>    return 0;
>}
>```



Thông thường hơn, chúng sẽ chỉ tạo ra giá trị hoặc hành vi sai:
>```
>#include <iostream>
>
>int main()
>{
>    int x; // no initializer provided
>    std::cout << x << '\n'; // Use of uninitialized variable leads to undefined result
>
>    return 0;
>}
>```

Hoặc:

>```
>#include <iostream>
>
>int add(int x, int y) // Hàm này được cho là thực hiện phép cộng
>{
>    return x - y; // Nhưng nó không thực hiện được do sử dụng sai toán tử
>}
>
>int main()
>{
>    std::cout << "5 + 3 = " << add(5, 3) << '\n'; // Nên trả về 8, nhưng trả về 2
>
>    return 0;
>}
>```

hay:
>```
>#include <iostream>
>
>int main()
>{
>    return 0; // function returns here
>
>    std::cout << "Hello, world!\n"; // so this never executes
>}
>```

Trình biên dịch hiện đại đã được cải thiện hơn trong việc phát hiện một số loại lỗi ngữ nghĩa phổ biến (ví dụ: sử dụng biến chưa được khởi tạo). Tuy nhiên, trong hầu hết các trường hợp, trình biên dịch sẽ không thể bắt được hầu hết các loại vấn đề này, vì trình biên dịch được thiết kế để kiểm tra ngữ pháp, không phải ý định của người viết code.

Trong các ví dụ trên, lỗi khá dễ dàng để phát hiện. Nhưng trong hầu hết các chương trình phức tạp, lỗi ngữ nghĩa không dễ dàng tìm thấy bằng cách nhìn trực tiếp vào mã nguồn. Đây là lúc các kỹ thuật gỡ lỗi có thể hữu ích.
