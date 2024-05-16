## **Bài 3.5: <u>Các chiến thuật gỡ lỗi cơ bản (tiếp theo)</u>** 

Trong bài học trước (3.4 - Các chiến thuật gỡ lỗi cơ bản), chúng ta đã bắt đầu tìm hiểu cách gỡ lỗi thủ công các vấn đề. Trong bài học đó, chúng ta đã chỉ ra một số hạn chế của việc sử dụng lệnh in để xuất văn bản gỡ lỗi:
- Lệnh in làm lộn xộn mã code.
- Lệnh in làm lộn xộn đầu ra chương trình.
- Thêm và xóa lệnh in yêu cầu sửa đổi mã code, có thể gây ra lỗi mới.
- Lệnh in cần phải được xóa sau khi sử dụng, khiến chúng không thể tái sử dụng.

**Chúng ta có thể cải thiện một số vấn đề này.** Trong bài học này, chúng ta sẽ khám phá một số kỹ thuật cơ bản để thực hiện việc đó.

### **Điều kiện hóa mã gỡ lỗi**

Hãy xem xét chương trình sau đây chứa một số lệnh in gỡ lỗi:
>```
>#include <iostream>
>
>int getUserInput()
>{
>std::cerr << "getUserInput() called\n";
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>    return x;
>}
>
>int main()
>{
>std::cerr << "main() called\n";
>    int x{ getUserInput() };
>    std::cout << "You entered: " << x << '\n';
>
>    return 0;
>}
>```

Khi bạn hoàn thành việc sử dụng lệnh gỡ lỗi, bạn cần xóa chúng hoặc chú thích chúng thành comment. Sau đó, nếu bạn muốn sử dụng lại chúng sau này, bạn sẽ phải thêm chúng trở lại hoặc bỏ chú thích comment.

Một cách để bật và tắt gỡ lỗi dễ dàng hơn trong toàn chương trình là sử dụng các chỉ thị tiền xử lý (preprocessor directives) để thêm điều kiện cho lệnh gỡ lỗi:
>```
>#include <iostream>
>
>#define ENABLE_DEBUG // Bỏ comment để bật gỡ lỗi
>
>int getUserInput()
>{
>#ifdef ENABLE_DEBUG
>std::cerr << "getUserInput() called\n";
>#endif
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>    return x;
>}
>
>int main()
>{
>#ifdef ENABLE_DEBUG
>std::cerr << "main() called\n";
>#endif
>    int x{ getUserInput() };
>    std::cout << "You entered: " << x << '\n';
>
>    return 0;
>}
>```

Bây giờ chúng ta có thể bật gỡ lỗi đơn giản bằng cách comment hoặc bỏ comment dòng `#define ENABLE_DEBUG`. Điều này cho phép chúng ta tái sử dụng các lệnh gỡ lỗi đã thêm trước đó và chỉ cần tắt chúng đi khi hoàn thành, thay vì phải xóa chúng khỏi mã code. Nếu đây là một chương trình gồm nhiều file, thì dòng `#define ENABLE_DEBUG` sẽ được đặt trong một file header được bao gồm vào tất cả các file code để chúng ta có thể comment hoặc bỏ comment dòng `#define` ở một vị trí duy nhất và nó sẽ áp dụng cho tất cả các file code.

Cách này giải quyết vấn đề phải xóa các lệnh gỡ lỗi và rủi ro khi làm như vậy, nhưng đổi lại, mã code sẽ bị thêm nhiều dòng hơn. Một nhược điểm khác của phương pháp này là nếu bạn đánh máy sai (ví dụ: đánh sai `"DEBUG"`) hoặc quên đưa file header vào một file code, thì một phần hoặc toàn bộ chức năng gỡ lỗi cho file đó có thể không được bật. Vì vậy, mặc dù phương pháp này tốt hơn so với phiên bản không điều kiện, nhưng vẫn còn chỗ để cải thiện.

### **Sử dụng Logger**

Một cách tiếp cận khác để gỡ lỗi có điều kiện thông qua bộ tiền xử lý là gửi thông tin gỡ lỗi của bạn đến một **log**. **Log** là một bản ghi tuần tự các sự kiện đã xảy ra, thường được gắn dấu thời gian. Quá trình tạo log được gọi là **logging (ghi log)**. Thông thường, log được ghi vào một file trên ổ đĩa (gọi là file log) để có thể xem lại sau này. Hầu hết các ứng dụng và hệ điều hành đều ghi file log có thể được sử dụng để giúp chẩn đoán các sự cố xảy ra.

File log có một vài ưu điểm. Vì thông tin được ghi vào file log được tách riêng khỏi đầu ra của chương trình của bạn, bạn có thể tránh được sự lộn xộn do việc trộn lẫn đầu ra thông thường và đầu ra gỡ lỗi. File log cũng có thể dễ dàng được gửi cho người khác để chẩn đoán - vì vậy nếu ai đó sử dụng phần mềm của bạn gặp sự cố, bạn có thể yêu cầu họ gửi cho bạn file log và nó có thể giúp bạn gợi ý vấn đề nằm ở đâu.

C++ chứa một luồng đầu ra được đặt tên là `std::clog` được dùng để ghi thông tin logging. Tuy nhiên, theo mặc định, `std::clog` ghi vào luồng lỗi chuẩn (giống như `std::cerr`). Mặc dù bạn có thể chuyển hướng nó sang file thay thế, đây là một lĩnh vực mà nhìn chung bạn nên sử dụng một trong nhiều công cụ logging của bên thứ ba hiện có. Công cụ nào bạn sử dụng phụ thuộc vào bạn.

Để minh họa, chúng tôi sẽ chỉ cho bạn cách xuất ra file log trông như thế nào bằng cách sử dụng logger **`plog`**. **`Plog`** được triển khai dưới dạng một tập hợp các file header, vì vậy nó có thể dễ dàng *include* bất cứ nơi nào bạn cần, và nó nhẹ và dễ sử dụng.

**Ví dụ sử dụng plog:**
>```
>#include <plog/Log.h> // Bước 1: include các header của logger
>#include <plog/Initializers/RollingFileInitializer.h>
>#include <iostream>
>
>int getUserInput()
>{
>    PLOGD << "getUserInput() called"; // PLOGD được định nghĩa bởi thư viện plog
>
>    std::cout << "Enter a number: ";
>    int x{};
>    std::cin >> x;
>    return x;
>}
>
>int main()
>{
>    plog::init(plog::debug, "Logfile.txt"); // Bước 2: khởi tạo logger
>
>    PLOGD << "main() called"; // Bước 3: Ghi thông tin vào log
>
>    int x{ getUserInput() };
>    std::cout << "You entered: " << x << '\n';
>
>    return 0;
>}
>```

Đoạn code ví dụ ở trên sử dụng thư viện logger plog để ghi thông tin ra file Logfile.txt. Đây là nội dung mẫu của file log:
>```
>2018-12-26 20:03:33.295 DEBUG [4752] [main@19] main() called
>2018-12-26 20:03:33.296 DEBUG [4752] [getUserInput@7] getUserInput() called
>```

Mỗi dòng trong file log đại diện cho một thông tin gỡ lỗi được ghi ra.

Các thông tin bao gồm:
- Ngày giờ (timestamp)
- Mức độ chi tiết (DEBUG trong trường hợp này)
- ID tiến trình
- Vị trí trong code gọi hàm logging (ví dụ: `main@19` nghĩa là hàm main dòng `19`)
- Nội dung thông tin gỡ lỗi ("`main() called`" và "`getUserInput() called`")

Trong bài học này, chúng tôi đã sử dụng thư viện `plog` để minh họa cách sử dụng logger. Tuy nhiên, các bài học sau sẽ không dùng `plog`.

>**Ngoài lề**<br>
>Nếu bạn muốn tự biên dịch code ví dụ ở trên hoặc sử dụng `plog` trong dự án của mình, bạn có thể làm theo các hướng dẫn sau (có thể bỏ qua nếu không cần):
>- Tải phiên bản plog mới nhất:
>- Truy cập kho lưu trữ [plog](https://github.com/SergiusTheBest/plog): 
>- Nhấp vào nút <span style="color:green">**Code**</span> màu xanh lá cây ở góc trên cùng bên phải và chọn `**"Download zip"**`.
>- Giải nén thư mục:
>- Giải nén toàn bộ file zip đã tải về một thư mục `somewhere` bất kỳ  trên ổ cứng.
>- Cấu hình thư mục include trong IDE:
>- Thiết lập thư mục `somewhere\plog-master\include\` (thay thế `somewhere` bằng đường dẫn thư mục giải nén) là thư mục include trong IDE của bạn.
>- Bạn có thể tham khảo hướng dẫn cụ thể cho Visual Studio tại [đây:](https://www.learncpp.com/cpp-tutorial/a2-using-libraries-with-visual-studio-2005-express/)
>- Và hướng dẫn cho Code::Blocks tại [đây:](https://www.learncpp.com/cpp-tutorial/a3-using-libraries-with-codeblocks/)
>
>**Vị trí file log:**
>- File log thường được tạo cùng thư mục với file thực thi của chương trình.

>**Lời khuyên:**<br>
>Trong các dự án lớn hoặc yêu cầu hiệu suất cao, bạn nên cân nhắc sử dụng các logger nhanh hơn và nhiều tính năng hơn, chẳng hạn như `spdlog`.
