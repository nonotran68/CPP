## **Bài 3.10: <u>Tìm kiếm lỗi trước khi chúng trở thành vấn đề</u>**

Khi bạn mắc **lỗi ngữ nghĩa (semantic error)**, lỗi đó có thể không được phát hiện ngay lập tức khi bạn chạy chương trình. Một vấn đề có thể ẩn náu không được phát hiện trong code của bạn trong một thời gian dài trước khi code mới được thêm vào hoặc các tình huống thay đổi khiến nó biểu hiện thành trục trặc của chương trình. Lỗi tồn tại trong code base càng lâu trước khi được tìm thấy thì càng khó tìm ra và thứ ban đầu có thể dễ sửa chữa lại biến thành một cuộc phiêu lưu gỡ rối tốn thời gian và năng lượng.

Vậy chúng ta có thể làm gì về điều đó?

### **Tránh lỗi ngay từ đầu: Bí kíp cho code "sạch"**

Cách tốt nhất là ngay từ đầu không mắc lỗi. Dưới đây là một số điều có thể giúp tránh mắc lỗi:
1. **Luôn tuân thủ các nguyên tắc lập trình tốt nhất:** Mỗi ngôn ngữ lập trình đều có những quy tắc riêng để đảm bảo code "sạch" và dễ hiểu. Hãy dành thời gian tìm hiểu và áp dụng các nguyên tắc này một cách nhất quán.
2. **Giữ "tinh thần minh mẫn" khi viết code:** Tránh lập trình khi bạn cảm thấy mệt mỏi hoặc căng thẳng. Hãy dành thời gian nghỉ ngơi và quay lại với tinh thần sảng khoái để đảm bảo sự tập trung và chính xác.
3. **Nắm rõ những "vùng nguy hiểm" trong ngôn ngữ:** Mỗi ngôn ngữ đều có những lỗi thường gặp mà người lập trình hay mắc phải. Hãy dành thời gian tìm hiểu và ghi nhớ những lỗi này để chủ động tránh mắc phải trong quá trình viết code.
4. **Giữ cho hàm ngắn gọn:** Hàm dài thường khiến code khó hiểu và dễ xảy ra lỗi. Hãy chia nhỏ các hàm dài thành nhiều hàm nhỏ hơn, mỗi hàm chỉ thực hiện một chức năng cụ thể.
5. **Tận dụng thư viện chuẩn:** Thay vì viết code "từ con số 0", hãy tận dụng các thư viện chuẩn được cung cấp sẵn bởi ngôn ngữ. Điều này giúp tiết kiệm thời gian và đảm bảo độ tin cậy cho code.
6. **Sử dụng comment (chú thích):** Thêm comment cho code sẽ giúp bạn dễ dàng hiểu lại code sau một thời gian hoặc chia sẻ code với người khác.
7. **Lập kế hoạch rõ ràng:** Hãy bắt đầu với các giải pháp đơn giản và dần dần thêm vào các tính năng phức tạp hơn. Tránh "tham lam" ôm đồm quá nhiều thứ ngay từ đầu.
8. **Ưu tiên sự đơn giản và dễ hiểu:** Tránh sử dụng những giải pháp "ảo diệu" hoặc khó hiểu. Hãy tập trung viết code dễ đọc và dễ bảo trì để việc sửa lỗi sau này trở nên dễ dàng hơn.
9. **Tối ưu hóa cho khả năng đọc và bảo trì:** Hiệu suất là quan trọng, nhưng không phải là yếu tố quyết định. Hãy ưu tiên viết code dễ đọc và dễ bảo trì để việc sửa lỗi và nâng cấp sau này trở nên thuận tiện hơn.

**Brian Kernighan**, tác giả của quyển ***"THE ELEMENTS OF PROGRAMMING STYLE"***, ấn bản thứ 2, đã từng nói: 
>*"Mọi người đều biết rằng gỡ rối khó gấp đôi so với việc viết chương trình ngay từ đầu. Vì vậy, nếu bạn cố gắng hết sức để thông minh khi viết code, làm thế nào bạn có thể gỡ rối nó?"*

### **Tái cấu trúc code (Refactoring)**

Khi bạn thêm các tính năng mới cho chương trình của mình ("thay đổi hành vi"), bạn sẽ thấy một số hàm của bạn dài hơn. Khi các hàm dài hơn, chúng trở nên phức tạp hơn và khó hiểu hơn.

Một cách để giải quyết vấn đề này là chia một hàm dài thành nhiều hàm ngắn hơn. Quá trình thực hiện các thay đổi cấu trúc cho code của bạn mà không làm thay đổi hành vi của nó được gọi là **tái cấu trúc (refactoring)**. Mục đích của tái cấu trúc là làm cho chương trình của bạn ít phức tạp hơn bằng cách tăng tính tổ chức và tính mô-đun của nó.

Vậy bao nhiêu dòng thì được coi là quá dài cho một hàm? Một hàm chiếm một màn hình theo chiều dọc được coi là quá dài - nếu bạn phải cuộn để đọc toàn bộ hàm, khả năng hiểu của hàm giảm đáng kể. Lý tưởng nhất, một hàm nên ít hơn mười dòng. Thậm chí các hàm dưới năm dòng còn tốt hơn.

Hãy nhớ rằng mục tiêu ở đây là tối đa hóa khả năng hiểu và bảo trì, chứ không phải giảm thiểu độ dài hàm - việc từ bỏ các thực hành tốt nhất hoặc sử dụng các kỹ thuật lập trình khó hiểu để tiết kiệm một hoặc hai dòng không có lợi cho code của bạn.

>**Lưu ý quan trọng**<br>
>Khi thực hiện thay đổi cho code của bạn, hãy thực hiện các thay đổi về hành vi HOẶC các thay đổi về cấu trúc, sau đó kiểm tra lại tính chính xác. Thực hiện các thay đổi về hành vi và cấu trúc cùng một lúc có xu hướng dẫn đến nhiều lỗi hơn cũng như các lỗi khó tìm hơn.

### **Giới thiệu về Lập trình phòng thủ (Defensive Programming)**

Lỗi không chỉ đến từ chính bạn (ví dụ: logic không chính xác) mà còn có thể xảy ra khi người dùng sử dụng ứng dụng theo cách bạn không lường trước. Ví dụ, nếu bạn yêu cầu người dùng nhập một số nguyên, nhưng họ lại nhập một chữ cái, chương trình của bạn sẽ hoạt động như thế nào trong trường hợp đó? Nếu bạn không lường trước điều này và thêm xử lý lỗi cho trường hợp này, thì có thể chương trình sẽ không hoạt động tốt.

Lập trình phòng thủ là một phương pháp mà lập trình viên cố gắng dự đoán tất cả các cách phần mềm có thể bị sử dụng sai cách bởi người dùng cuối, hoặc bởi các nhà phát triển khác (bao gồm cả chính lập trình viên) sử dụng code. Những cách sử dụng sai này thường có thể được phát hiện và sau đó giảm thiểu (ví dụ: yêu cầu người dùng nhập sai dữ liệu thử lại).

Chúng ta sẽ khám phá các chủ đề liên quan đến xử lý lỗi (error handling) trong các bài học tiếp theo.

### **Tìm lỗi nhanh chóng** 

Vì việc không mắc lỗi trong các chương trình lớn là khó khăn, nên điều tốt nhất tiếp theo là bắt lỗi bạn mắc phải một cách nhanh chóng.

Cách tốt nhất để thực hiện việc này là lập trình từng phần nhỏ một, sau đó kiểm tra code của bạn và đảm bảo nó hoạt động.

Tuy nhiên, còn một vài kỹ thuật khác mà chúng ta cũng có thể sử dụng.

### **Giới thiệu về hàm kiểm thử (Testing functions)** 

Một cách phổ biến để giúp phát hiện các vấn đề với chương trình của bạn là viết các hàm kiểm thử để "kiểm tra" code bạn đã viết. Đây là một ví dụ cơ bản, nhằm mục đích minh họa hơn bất cứ điều gì khác:

>```
>#include <iostream>
>
>int add(int x, int y)
>{
>    return x + y;
>}
>
>void testadd()
>{
>    std::cout << "Hàm này sẽ in: 2 0 0 -2\n";
>    std::cout << add(1, 1) << ' ';
>    std::cout << add(-1, 1) << ' ';
>    std::cout << add(1, -1) << ' ';
>    std::cout << add(-1, -1) << ' ';
>}
>
>int main()
>{
>    testadd();
>
>    return 0;
>}
>```

Hàm `testadd()` kiểm thử hàm `add()` bằng cách gọi nó với các giá trị khác nhau. Nếu tất cả các giá trị khớp với mong đợi của chúng tôi, thì chúng tôi có thể tin tưởng hợp lý rằng hàm hoạt động. Thậm chí tốt hơn, chúng ta có thể giữ hàm này xung quanh và chạy nó bất cứ khi nào chúng ta thay đổi hàm `add` để đảm bảo chúng ta không vô tình làm hỏng nó.

Đây là một dạng đơn giản của **kiểm thử đơn vị (unit testing)**, đây là một phương pháp kiểm thử phần mềm theo đó các đơn vị nhỏ của mã nguồn được kiểm thử để xác định xem chúng có chính xác hay không.

Giống như các **khung ghi nhật ký (logging frameworks)**, có nhiều khung kiểm thử đơn vị của bên thứ 3 có thể được sử dụng. Cũng có thể viết khung của riêng bạn, mặc dù chúng ta sẽ cần nhiều tính năng ngôn ngữ hơn để thực hiện chủ đề một cách công bằng. Chúng ta sẽ quay lại một số điều này trong bài học sau.

### **Giới thiệu về Ràng buộc (Constraints)**

Ràng buộc là một kỹ thuật lập trình nhằm **kiểm soát** và **đảm bảo** tính chính xác của chương trình bằng cách **thiết lập các điều kiện** mà chương trình phải tuân theo. Kỹ thuật này đặc biệt hữu ích khi xử lý các vấn đề phức tạp có nhiều yếu tố liên quan và cần đảm bảo sự nhất quán trong dữ liệu.

**Cách thức hoạt động:**
- **Xác định ràng buộc:** Bắt đầu bằng cách xác định các ràng buộc mà chương trình cần đáp ứng. Ví dụ: trong bài toán tính giai thừa, ràng buộc là số đầu vào phải không âm.
- **Thêm điều kiện kiểm tra:** Viết code để kiểm tra xem các ràng buộc có được đáp ứng hay không. Sử dụng các câu lệnh như `assert` hoặc `static_assert` để báo lỗi nếu có bất kỳ ràng buộc nào bị vi phạm. Chúng ta sẽ đề cập trong bài học 9.6 - `assert` và `static_assert`.

**Lợi ích:**
- **Phát hiện lỗi sớm:** Ràng buộc giúp phát hiện lỗi ngay lập tức, ngay khi chúng xảy ra, thay vì đợi đến khi chương trình chạy và tạo ra kết quả sai.
- **Tăng độ tin cậy:** Bằng cách đảm bảo các ràng buộc luôn được tuân thủ, ràng buộc giúp tăng độ tin cậy và tính chính xác của chương trình.
- **Cải thiện khả năng bảo trì:** Code sử dụng ràng buộc thường dễ đọc và dễ hiểu hơn, giúp việc bảo trì và sửa lỗi sau này trở nên dễ dàng hơn.

**Ví dụ:**
>```
>int factorial(int n) {
>  // Kiểm tra ràng buộc: số đầu vào phải không âm
>  assert(n >= 0);
>
>  // Tính giai thừa
>  if (n == 0) {
>    return 1;
>  } else {
>    return n * factorial(n - 1);
>  }
>}
>```

Trong ví dụ này, hàm `factorial` sử dụng câu lệnh `assert` để kiểm tra xem số đầu vào `n` có không âm hay không. Nếu điều kiện không được đáp ứng, hàm sẽ báo lỗi ngay lập tức, ngăn chặn việc tính toán sai và giúp lập trình viên phát hiện lỗi sớm.

>**Lưu ý:**
>- Ràng buộc có thể làm giảm hiệu suất chương trình do các phép kiểm tra bổ sung.
>- Cần sử dụng ràng buộc một cách hợp lý và tránh lạm dụng, vì có thể dẫn đến code rườm rà và khó hiểu.

### **Săn lùng lỗi tiềm ẩn với Static Analysis Tool**

Lập trình viên thường mắc phải những lỗi phổ biến nhất định, và một số lỗi đó có thể được phát hiện bởi các **công cụ chuyên dụng**. Các công cụ này, được gọi là **công cụ phân tích tĩnh (static analysis tool)** hay **linter**, sẽ phân tích code của bạn để xác định các vấn đề ngữ nghĩa cụ thể.

**Phân tích tĩnh** hoạt động trên code nguồn, giúp nhận diện các lỗi tiềm ẩn mà không cần chạy chương trình. Các vấn đề được phát hiện bởi công cụ này có thể hoặc không phải là nguyên nhân của lỗi thực tế, nhưng nó sẽ giúp bạn xác định các khu vực code dễ hỏng hoặc có thể gây ra rắc rối trong một số trường hợp.

Bạn đã có một công cụ phân tích tĩnh sẵn có - đó chính là **trình biên dịch** của bạn. Ngoài việc đảm bảo chương trình cú pháp chính xác, hầu hết các trình biên dịch C++ hiện đại đều thực hiện phân tích tĩnh cơ bản để xác định một số vấn đề phổ biến. Ví dụ: trình biên dịch sẽ cảnh báo bạn nếu bạn cố gắng sử dụng một biến chưa được khởi tạo. Nếu bạn chưa thực hiện, việc bật cảnh báo và mức lỗi của trình biên dịch (xem bài học 0.11 - Cấu hình trình biên dịch: Cảnh báo và mức lỗi) có thể giúp hiển thị các vấn đề này.

Ngoài trình biên dịch, còn có rất nhiều công cụ phân tích tĩnh khác với khả năng xác định hơn 300 loại lỗi lập trình. Việc sử dụng công cụ phân tích tĩnh là tùy chọn cho các chương trình học thuật nhỏ, nhưng được khuyến nghị mạnh mẽ cho các chương trình lớn vì nó có thể phát hiện hàng chục hoặc hàng trăm vấn đề tiềm ẩn.

>**Khuyến nghị**<br>
>Sử dụng công cụ phân tích tĩnh trên chương trình của bạn để tìm các khu vực code không tuân theo các thực hành tốt nhất.

>**Dành cho người dùng Visual Studio**<br>
>Visual Studio 2019 trở lên đi kèm với công cụ phân tích tĩnh tích hợp. Bạn có thể truy cập nó bằng cách *Build > Run Code Analysis on Solution (Alt+F11)*.

>**Mẹo**<br>
>Dưới đây là một số công cụ phân tích tĩnh phổ biến:
>
>**Miễn phí:**
>- [clang-tidy](https://clang.llvm.org/extra/clang-tidy/)
>- [cpplint](https://github.com/cpplint/cpplint)
>- [cppcheck](https://cppcheck.sourceforge.io/) (đã tích hợp vào Code::Blocks)
>- [SonarLint](https://www.sonarsource.com/open-source-editions/)
>
>Hầu hết các công cụ này đều có extensions để tích hợp vào IDE của bạn. Ví dụ: [Clang Power Tools](https://marketplace.visualstudio.com/items?itemName=caphyon.ClangPowerTools).
>
>**Trả phí (có thể miễn phí cho các dự án Mã nguồn mở):**
>- [Coverity](https://www.synopsys.com/software-integrity/security-testing/static-analysis-sast.html)
>- [SonarQube](https://www.sonarsource.com/products/sonarqube/)

Sử dụng công cụ phân tích tĩnh là một cách hiệu quả để tăng độ tin cậy, chính xác và khả năng bảo trì của chương trình. Bằng cách phát hiện sớm các lỗi tiềm ẩn, bạn có thể tiết kiệm thời gian và công sức trong quá trình phát triển phần mềm.
