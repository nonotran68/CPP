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

