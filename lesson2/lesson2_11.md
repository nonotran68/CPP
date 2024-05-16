## **Bài 2.11: <u>Tệp tiêu đề (header files)</u>**

### **Tiêu đề và mục đích của chúng**

Khi chương trình phát triển lớn hơn (và sử dụng nhiều tệp hơn), việc phải khai báo trước mọi hàm bạn muốn sử dụng được định nghĩa trong một tệp khác sẽ ngày càng tẻ nhạt. Sẽ không tuyệt vời sao nếu bạn có thể đặt tất cả các khai báo trước của mình vào một vị trí và sau đó nhập chúng khi cần?

Các tệp mã C++ (có phần mở rộng .cpp) không phải là tệp duy nhất thường thấy trong các chương trình C++. Loại tệp khác được gọi là tệp tiêu đề (header file). Tệp tiêu đề thường có phần mở rộng là .h, nhưng đôi khi bạn sẽ thấy chúng có phần mở rộng là .hpp hoặc không có phần mở rộng nào cả. Mục đích chính của một tệp header là truyền các khai báo đến các tệp mã (.cpp).

>**Điểm mấu chốt**<br>
>Tệp header cho phép chúng ta đặt các khai báo ở một vị trí và sau đó nhập chúng bất cứ nơi nào chúng ta cần. Điều này có thể giúp tiết kiệm rất nhiều việc gõ phím trong các chương trình đa tệp.

### **Sử dụng tệp tiêu đề của thư viện chuẩn**

**Xem xét chương trình sau:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Hello, world!";
>    return 0;
>}
>```

Chương trình này in "`Hello, world!`" ra console bằng cách sử dụng `std::cout`. Tuy nhiên, chương trình này không bao giờ cung cấp định nghĩa hoặc khai báo cho `std::cout`, vậy trình biên dịch biết `std::cout` là gì?

Câu trả lời là `std::cout` đã được khai báo trước trong tệp header "`iostream`". Khi chúng ta `#include <iostream>`, chúng ta yêu cầu bộ tiền xử lí sao chép tất cả nội dung (bao gồm cả khai báo trước cho `std::cout`) từ tệp có tên "`iostream`" vào tệp thực hiện việc `#include`.

>**Điểm mấu chốt**<br>
>Khi bạn `#include` một tệp, nội dung của tệp được *include* sẽ được chèn vào điểm *include*. Điều này cung cấp một cách hữu ích để kéo các khai báo từ tệp khác.

Hãy xem xét điều gì sẽ xảy ra nếu header `iostream` không tồn tại. Bất cứ nơi nào bạn sử dụng `std::cout`, bạn sẽ phải nhập hoặc sao chép thủ công tất cả các khai báo liên quan đến `std::cout` vào đầu mỗi tệp sử dụng `std::cout`! Điều này sẽ đòi hỏi rất nhiều kiến thức về cách `std::cout` được khai báo và sẽ là một khối lượng công việc lớn. Thậm chí tệ hơn, nếu một nguyên mẫu hàm được thêm hoặc thay đổi, chúng ta sẽ phải cập nhật thủ công tất cả các khai báo trước.

Vì vậy, việc sử dụng `#include <iostream>` đơn giản hơn nhiều!

### **Sử dụng tệp tiêu đề để truyền vào các tiền khai báo**

Bây giờ chúng ta hãy quay lại ví dụ mà chúng ta đã thảo luận trong bài học trước. Khi kết thúc, chúng ta có hai tệp, `add.cpp` và `main.cpp`, trông như thế này:

**add.cpp:**
>```
>int add(int x, int y)
>{
>    return x + y;
>}
>```

**main.cpp:**
>```
>#include <iostream>
>
>int add(int x, int y); // Khai báo trước bằng cách sử dụng nguyên mẫu hàm
>
>int main()
>{
>    std::cout << "Tổng của 3 và 4 là " << add(3, 4) << '\n';
>    return 0;
>}
>```

(Nếu bạn đang tạo lại ví dụ này từ đầu, đừng quên thêm add.cpp vào project của bạn để nó được biên dịch).

Trong ví dụ này, chúng ta đã sử dụng một khai báo trước để trình biên dịch biết định danh `add` là gì khi biên dịch `main.cpp`. Như đã đề cập trước đây, việc thêm thủ công các khai báo trước cho mọi hàm bạn muốn sử dụng nằm trong một tệp khác có thể nhanh chóng trở nên tẻ nhạt.

Hãy viết một tệp tiêu đề để giải quyết vấn đề này. Viết một tệp tiêu đề là một điều dễ dàng đáng ngạc nhiên, vì tệp chỉ bao gồm hai phần:

**Bộ bảo vệ tiêu đề (header guard)**, chúng ta sẽ thảo luận chi tiết hơn trong bài học tiếp theo (**2.12 - Bộ bảo vệ tiêu đề**).
Nội dung thực tế của tệp tiêu đề, đây nên là các tiền khai báo cho tất cả các định danh mà chúng ta muốn các tệp khác có thể nhìn thấy.
Việc thêm một tệp tiêu đề vào project hoạt động tương tự như việc thêm một tệp mã nguồn (được đề cập trong bài học **2.8 - Chương trình với nhiều tệp mã**).

Nếu đang sử dụng IDE, hãy thực hiện các bước tương tự và chọn **"Header"** thay vì **"Source"** khi được hỏi. Tệp tiêu đề sẽ xuất hiện như một phần của project.

Nếu sử dụng dòng lệnh, chỉ cần tạo một tệp mới trong trình soạn thảo yêu thích của bạn trong cùng thư mục với các tệp nguồn (.cpp) của bạn. Không giống như các tệp nguồn, tệp tiêu đề không nên được thêm vào lệnh biên dịch của bạn (chúng được bao gồm ngầm theo các lệnh `#include` và được biên dịch như một phần của các tệp nguồn).

>**Thực hành tốt nhất**<br>
>Ưu tiên sử dụng hậu tố *.h* khi đặt tên cho các tệp tiêu đề của bạn (trừ khi project của bạn đã tuân theo một quy ước khác).

Đây là một quy ước lâu đời cho các tệp tiêu đề C++, và hầu hết các IDE vẫn mặc định sử dụng *.h* thay vì các tùy chọn khác.

Các tệp tiêu đề thường được ghép nối với các tệp mã, với tệp tiêu đề cung cấp các tiền khai báo cho tệp mã tương ứng. Vì tệp tiêu đề của chúng ta sẽ chứa một tiền khai báo cho các hàm được định nghĩa trong `add.cpp`, chúng tôi sẽ đặt tên cho tệp header mới của chúng tôi là `add.h`.

>**Thực hành tốt nhất**<br>
>Nếu một tệp tiêu đề được ghép nối với một tệp mã (ví dụ: `add.h` với `add.cpp`), thì cả hai đều nên có cùng tên cơ sở (`add`).

**Ví dụ:**

**add.h:**
>```
>// 1) Thực sự chúng ta nên có một header guard ở đây, nhưng sẽ bỏ qua nó để đơn giản >(chúng tôi sẽ đề cập đến header guard trong bài học tiếp theo)
>// 2) Đây là nội dung của tệp .h, đây là nơi chứa các khai báo
>int add(int x, int y); // Nguyên mẫu hàm cho add.h - đừng quên dấu chấm phẩy!
>```

Để sử dụng tệp tiêu đề này trong `main.cpp`, chúng ta phải *include* nó (sử dụng dấu ngoặc kép `""`, không sử dụng dấu ngoặc góc (`<>`).

**main.cpp:**
>```
>#include "add.h" // Chèn nội dung của add.h tại đây. Lưu ý sử dụng dấu ngoặc kép
>#include <iostream>
>
>int main()
>{
>    std::cout << "Tổng của 3 và 4 là " << add(3, 4) << '\n';
>    return 0;
>}
>```

**add.cpp:**
>```
>#include "add.h" // Chèn nội dung của add.h tại đây. Lưu ý sử dụng dấu ngoặc kép ở đây.
>
>int add(int x, int y)
>{
>    return x + y;
>}
>```

Khi bộ tiền xử lý xử lý dòng `#include "add.h"`, nó sao chép nội dung của `add.h` vào tệp hiện tại tại thời điểm đó. Bởi vì `add.h` của chúng tôi chứa một tiền khai báo cho hàm `add()`, khai báo trước đó sẽ được sao chép vào `main.cpp`. Kết quả cuối cùng là một chương trình có chức năng giống như chương trình mà chúng tôi đã thêm thủ công khai báo trước ở đầu `main.cpp`.

![minh họa](IncludeHeader.webp)

### **Tại sao việc bao gồm các định nghĩa trong tệp tiêu đề lại dẫn đến vi phạm quy tắc định nghĩa một lần (ODR)**

Hiện tại, bạn nên tránh đặt định nghĩa hàm hoặc biến trong các tệp header. Việc làm như vậy thường sẽ dẫn đến vi phạm **quy tắc định nghĩa một lần (ODR)** trong các trường hợp tệp tiêu đề được *include* vào nhiều hơn một tệp nguồn.

>**Nội dung liên quan**<br>
>Chúng tôi đã đề cập đến **quy tắc định nghĩa một lần (ODR)** trong bài học [**2.7 - Khai báo trước và định nghĩa**](lesson2_7.ipynb).

Hãy minh họa cách điều này xảy ra:

**add.h:**
>```
>// Thực sự chúng ta nên có một header guard ở đây, nhưng sẽ bỏ qua nó để đơn giản (chúng tôi sẽ đề cập đến header guard trong bài học tiếp theo)
>
>// Định nghĩa cho add() trong tệp header - không nên làm điều này!
>int add(int x, int y)
>{
>    return x + y;
>}
>```

**main.cpp:**
>```
>#include "add.h" // Nội dung của add.h được sao chép tại đây
>#include <iostream>
>
>int main()
>{
>    std::cout << "Tổng của 3 và 4 là " << add(3, 4) << '\n';
>
>    return 0;
>}
>```

**add.cpp:**
>```
>#include "add.h" // Nội dung của add.h được sao chép tại đây
>```

Khi `main.cpp` được biên dịch, `#include "add.h"` sẽ được thay thế bằng nội dung của `add.h` rồi mới được biên dịch. Do đó, trình biên dịch sẽ biên dịch thứ gì đó trông giống như thế này:

**main.cpp (sau khi tiền xử lý):**
>```
>// từ add.h:
>int add(int x, int y)
>{
>    return x + y;
>}
>
>// nội dung của header iostream ở đây
>
>int main()
>{
>    std::cout << "Tổng của 3 và 4 là " << add(3, 4) << '\n';
>
>    return 0;
>}
>```

Các tệp này sẽ được biên dịch tốt.

Khi trình biên dịch biên dịch `add.cpp`, `#include "add.h"` sẽ được thay thế bằng nội dung của `add.h` rồi mới được biên dịch. Do đó, trình biên dịch sẽ biên dịch thứ gì đó trông giống như thế này:

**add.cpp (sau khi tiền xử lý):**
>```
>int add(int x, int y)
>{
>    return x + y;
>}
>```

Cuối cùng, trình liên kết sẽ chạy. Và trình liên kết sẽ thấy rằng bây giờ có hai định nghĩa cho hàm `add()`: một trong `main.cpp` và một trong `add.cpp`. Đây là vi phạm phần 2 của **ODR**, quy định, **"Trong một chương trình nhất định, một biến hoặc hàm thông thường chỉ có thể có một định nghĩa."**

>**Thực hành tốt nhất**<br>
>- Không đặt định nghĩa hàm và biến trong các tệp tiêu đề của bạn (hiện tại).
>- Việc định nghĩa bất kỳ thứ nào trong số này trong tệp tiều đề có thể sẽ dẫn đến vi phạm quy tắc định nghĩa một lần (ODR) nếu tệp tiêu đề đó sau đó được `#include` vào nhiều hơn một tệp nguồn (.cpp).

>**Lưu ý của tác giả**<br>
>Trong các bài học tiếp theo, chúng ta sẽ gặp các loại định nghĩa bổ sung có thể được định nghĩa an toàn trong các tệp tiêu đề (bởi vì chúng được miễn trừ **ODR**). Điều này bao gồm các định nghĩa cho các hàm nội tuyến, biến nội tuyến, kiểu và khuôn mẫu. Chúng tôi sẽ thảo luận thêm về điều này khi chúng tôi giới thiệu từng loại này.

### **Các tệp nguồn nên `include` tệp tiêu đề đi kèm của chúng**

Trong C++, đây là cách thực hành tốt nhất để các tệp mã sử dụng `#include` tệp tiêu đề đi kèm của chúng (nếu có). Trong ví dụ trên, `add.cpp` sẽ *include* `add.h`.

Điều này cho phép trình biên dịch phát hiện một số loại lỗi nhất định ở thời gian biên dịch thay vì thời gian liên kết. **Ví dụ:**

**something.h:**
>```
>int something(int); // kiểu trả về của khai báo trước là int (int)
>```

**something.cpp:**
>```
>#include "something.h"
>
>void something(int) // lỗi: kiểu trả về không khớp
>{
>}
>```


Vì `something.cpp` đã *include* `something.h`, trình biên dịch sẽ nhận thấy rằng hàm `something()` có kiểu trả về không khớp và cung cấp cho chúng ta lỗi biên dịch. Nếu `something.cpp` không bao gồm `something.h`, chúng ta sẽ phải đợi cho đến khi trình liên kết phát hiện ra sự không khớp, điều này gây lãng phí thời gian. Để biết một ví dụ khác, hãy xem [bình luận này](https://www.learncpp.com/cpp-tutorial/header-files/comment-page-8/#comment-398571).

Chúng ta cũng sẽ thấy nhiều ví dụ trong các bài học tiếp theo, nơi nội dung mà tệp nguồn yêu cầu được định nghĩa trong tệp tiêu đề đi kèm. Trong những trường hợp như vậy, việc *include* tệp tiêu đề là cần thiết.

>**Thực hành tốt nhất**<br>
>Các tệp nguồn nên *include* tệp tiêu đề được ghép nối của chúng (nếu có).

### **Không *include* các tệp .cpp**

Mặc dù bộ tiền xử lí sẽ vui vẻ thực hiện việc đó, bạn thường không nên include các tệp .cpp. Chúng nên được thêm vào project của bạn và được biên dịch.

Có một số lý do cho việc này:
- Thực hiện việc này có thể gây ra xung đột đặt tên giữa các tệp nguồn.
- Trong một project lớn, có thể khó tránh được các vấn đề về quy tắc định nghĩa 1 lần (ODR).
- Bất kỳ thay đổi nào đối với một tệp .cpp như vậy sẽ khiến cả tệp .cpp đó và bất kỳ tệp .cpp nào khác *include* nó phải được biên dịch lại, điều này có thể mất nhiều thời gian. Các tệp tiêu đề có xu hướng thay đổi ít thường xuyên hơn các tệp nguồn.
- Nó không theo quy ước.

>**Thực hành tốt nhất**<br>
>Tránh include các tệp .cpp.

>**Mẹo**<br>
>Nếu project của bạn không được biên dịch trừ khi bạn *include* các tệp .cpp, điều đó có nghĩa là các tệp .cpp đó không được biên dịch như một phần của project. Thêm chúng vào project hoặc dòng lệnh của bạn để chúng được biên dịch.

### **Khắc phục sự cố (troubleshooting)**

Nếu bạn gặp lỗi trình biên dịch cho biết `add.h` không được tìm thấy, hãy đảm bảo tệp đó thực sự được đặt tên là `add.h`. Tùy thuộc vào cách bạn tạo và đặt tên cho nó, tệp có thể được đặt tên là `add` (không có phần mở rộng) hoặc `add.h.txt` hoặc `add.hpp`. Ngoài ra, hãy đảm bảo nó nằm trong cùng thư mục với các tệp mã còn lại của bạn.

Nếu bạn gặp lỗi liên kết về hàm `add` không được định nghĩa, hãy đảm bảo bạn đã bao gồm `add.cpp` vào project của mình để định nghĩa cho hàm `add` có thể được liên kết vào chương trình.

### **Dấu ngoặc góc vs. dấu ngoặc kép**


Có lẽ bạn đang tò mò tại sao chúng tôi sử dụng dấu ngoặc góc cho `iostream`, và dấu ngoặc kép cho `add.h`. Có khả năng là một tệp tiêu đề có cùng tên tệp có thể tồn tại trong nhiều thư mục. Việc chúng tôi sử dụng dấu ngoặc góc so với dấu ngoặc kép giúp cung cấp cho bộ tiền xử lí một manh mối về nơi nó nên tìm các tệp tiêu đề.

Khi chúng tôi sử dụng dấu ngoặc góc, chúng ta đang nói với bộ tiền xử lí rằng đây là một tệp tiêu đề mà chúng ta không tự viết. Bộ tiền xử lí sẽ chỉ tìm kiếm tệp tiêu đề trong các thư mục được chỉ định bởi các **thư mục include** (include directories). Các **thư mục include** được cấu hình như một phần của **cài đặt project/IDE/cài đặt trình biên dịch** và thường mặc định thành các thư mục chứa các tệp tiêu đề đi kèm với trình biên dịch và/hoặc hệ điều hành hoặc thư viện của bên thứ ba mà bạn đã cài đặt ở một vị trí khác trên hệ thống của mình. Bộ tiền xử lí sẽ không tìm kiếm tệp tiêu đề trong thư mục mã nguồn của project của bạn.

Khi chúng tôi sử dụng dấu ngoặc kép, chúng ta đang nói với bộ tiền xử lí rằng đây là một tệp tiêu đề do chúng ta viết. Bộ tiền xử lí sẽ đầu tiên tìm kiếm tệp tiêu đề trong thư mục hiện tại. Nếu nó không thể tìm thấy tệp tiêu đề phù hợp ở đó, thì nó sẽ tìm kiếm các **thư mục include**.

>**Quy tắc**<br>
>- Sử dụng dấu ngoặc kép để *include* các tệp tiêu đề do bạn viết hoặc được dự kiến tìm thấy trong thư mục hiện tại.
>- Sử dụng dấu ngoặc nhọn để *include* các tệp tiêu đề đi kèm với trình biên dịch, hệ điều hành hoặc thư viện của bên thứ ba mà bạn đã cài đặt ở một vị trí khác trên hệ thống của mình.


### **Tại sao `iostream` không có phần mở rộng .h?**

Một câu hỏi thường được hỏi khác là "Tại sao `iostream` (hoặc bất kỳ tệp tiêu đề nào khác trong thư viện chuẩn) không có phần mở rộng .h?". Câu trả lời là `iostream.h` là một tệp tiêu đề khác với iostream! Để giải thích cần một bài học lịch sử ngắn.

Khi C++ lần đầu tiên được tạo ra, tất cả các tệp trong thư viện chuẩn đều kết thúc bằng hậu tố .h. Phiên bản gốc của `cout` và `cin` được khai báo trong `iostream.h`. Khi ngôn ngữ được ủy ban ANSI chuẩn hóa, họ đã quyết định chuyển tất cả các tên được sử dụng trong thư viện chuẩn vào không gian tên `std` để giúp tránh xung đột đặt tên với các định danh do người dùng khai báo. Tuy nhiên, điều này đã gây ra một vấn đề: nếu họ di chuyển tất cả các tên vào không gian tên `std`, thì không có chương trình cũ nào (bao gồm `iostream.h`) hoạt động nữa!

Để giải quyết vấn đề này, một tập hợp mới các tệp tiêu đề đã được giới thiệu mà không có phần mở rộng .h. Các tệp tiêu đề mới này khai báo tất cả các tên bên trong không gian tên `std`. Bằng cách này, các chương trình cũ hơn bao gồm `#include <iostream.h>` không cần phải viết lại và các chương trình mới hơn có thể `#include <iostream>`.

>**Kiến thức sâu sắc**
>- Các tệp header với phần mở rộng .h khai báo tên của chúng trong không gian tên toàn cục. Chúng cũng có thể tùy chọn khai báo các tên đó trong không gian tên `std`.
>- Các tệp header không có phần mở rộng .h khai báo tên của chúng trong không gian tên `std`. Thật không may và ngu ngốc, các tệp tiêu đề này cũng có thể tùy chọn khai báo các tên đó trong không gian tên toàn cục.

Ngoài ra, nhiều thư viện được thừa hưởng từ C mà vẫn hữu ích trong C++ được đặt tiền tố *c* (ví dụ: stdlib.h trở thành cstdlib).

>**Thực hành tốt nhất**<br>
>- Khi *include* một tệp tiêu đề từ thư viện chuẩn, hãy sử dụng phiên bản không có phần mở rộng .h nếu nó tồn tại. Các header do người dùng định nghĩa vẫn nên sử dụng phần mở rộng .h.
>- Nếu một tệp tiêu đề không có phần mở rộng .h khai báo tên vào không gian tên toàn cục, hãy tránh các tên đó, vì chúng có thể không khả dụng trong không gian tên toàn cục trên các trình biên dịch khác. Thay vào đó, hãy ưu tiên các tên được khai báo trong không gian tên `std`.

### **Include các tệp tiêu đề từ các thư mục khác**

Một câu hỏi phổ biến khác liên quan đến cách include các tệp tiêu đề từ các thư mục khác.

Một cách (không tốt) để thực hiện việc này là include một đường dẫn tương đối đến tệp tiêu đề bạn muốn *include* như một phần của dòng `#include`. 

**Ví dụ:**
>```
>#include "headers/myHeader.h"
>#include "../moreHeaders/myOtherHeader.h"

Mặc dù tệp này sẽ biên dịch (giả sử các tệp tồn tại trong các thư mục đường dẫn tương đối đó), nhược điểm của cách tiếp cận này là nó yêu cầu bạn phải giữ nguyên cấu trúc thư mục của mình trong code. Nếu bạn cập nhật cấu trúc thư mục của mình, code của bạn sẽ không hoạt động nữa.

Một phương pháp tốt hơn là cho trình biên dịch hoặc IDE của bạn biết rằng bạn có một số tệp tiêu đề ở một vị trí khác, để nó có thể tìm kiếm ở đó khi không tìm thấy chúng trong thư mục hiện tại. Điều này thường có thể được thực hiện bằng cách đặt *đường dẫn include* (include path) hoặc *thư mục tìm kiếm* (search directory) trong cài đặt project IDE của bạn.

>**Đối với người dùng Visual Studio**
>
>Click chuột phải vào project của bạn trong **Solution Explorer**, và chọn **Properties**, sau đó là tab **VC++ Directories**. Tại đây, bạn sẽ thấy một dòng được gọi là **Include Directories**. Thêm các thư mục bạn muốn trình biên dịch tìm kiếm các tệp tiêu đề bổ sung ở đó.

>**Đối với người dùng Code::Blocks**
>
>Trong Code::Blocks, hãy vào menu **Project** và chọn **Build Options**, sau đó là tab **Search directories**. Thêm các thư mục bạn muốn trình biên dịch tìm kiếm các tệp tiêu đề bổ sung ở đó.

>**Đối với người dùng GCC/G++**
>
>Sử dụng `g++`, bạn có thể sử dụng tùy chọn `-I` để chỉ định một thư mục include thay thế:
>
>>`g++ -o main -I/source/includes main.cpp`

>**Đối với người dùng VS Code**
>
>Trong file cấu hình `tasks.json` của bạn, thêm một dòng mới trong phần `“Args”`:
>
>>**JSON**
>>
>>`"-I/source/includes",`

Điều tuyệt vời về cách tiếp cận này là nếu bạn thay đổi cấu trúc thư mục của mình, bạn chỉ cần thay đổi một cài đặt trình biên dịch hoặc IDE duy nhất thay vì mọi tệp code.

### **Các tệp tiêu đề có thể chèn các tệp tiêu đề khác**

Thông thường, một tệp tiêu đề sẽ cần một khai báo hoặc định nghĩa nằm trong một tệp header khác. Do đó, các tệp header thường sẽ `#include` các tệp tiêu đề khác.

Khi tệp mã của bạn `#include` tệp tiêu đề đầu tiên, bạn cũng sẽ nhận được bất kỳ tệp tiêu đề nào khác mà tệp tiêu đề đầu tiên *include* (và bất kỳ tệp tiêu đề nào chúng *include*, v.v.). Các tệp tiêu đề bổ sung này đôi khi được gọi là ***include* trung gian**, vì chúng được *include* ngầm  chứ không phải rõ ràng.

Nội dung của các *include* trung gian này có sẵn để sử dụng trong tệp mã của bạn. Tuy nhiên, bạn thường không nên dựa vào nội dung của các tệp tiêu đề được *include* trung gian (trừ khi tài liệu tham khảo cho biết các *include* trung gian đó là cần thiết). Việc triển khai các tệp tiêu đề có thể thay đổi theo thời gian hoặc khác nhau trên các hệ thống khác nhau. Nếu điều đó xảy ra, code của bạn chỉ có thể biên dịch trên một số hệ thống nhất định hoặc có thể biên dịch bây giờ nhưng không biên dịch được trong tương lai. Điều này có thể dễ dàng tránh được bằng cách *include* rõ ràng tất cả các tệp header mà nội dung của tệp code của bạn yêu cầu.

>**Cách thực hành tốt nhất**<br>
>Mỗi tệp nên `#include` rõ ràng tất cả các tệp tiêu đề mà nó cần để biên dịch. Không dựa vào các tiêu đề được đưa vào tạm thời từ các tiêu đề khác.

Thật không may, không có cách nào dễ dàng để phát hiện khi tệp mã của bạn vô tình dựa vào nội dung của tệp tiêu đề đã được một tệp tiêu đề khác đưa vào.

>**<u>Hỏi:</u> Tôi đã không *include* `<someheader>` và chương trình của tôi vẫn hoạt động! Tại sao?**<br>
>Đây là một trong những câu hỏi thường gặp nhất trên trang web này.<br>
>Câu trả lời là: nó có thể hoạt động vì bạn đã chèn một số tiêu đề khác (ví dụ: `<iostream>`), chính tiêu đề này đã bao gồm `<someheader>`. Mặc dù chương trình của bạn sẽ biên dịch nhưng theo cách thực hành tốt nhất ở trên, bạn không nên dựa vào điều này. Những gì biên dịch cho bạn có thể không biên dịch được trên máy của người khác.

### **Thứ tự của các file tiêu đề sử dụng `#include`**

Nếu các file header của bạn được viết đúng cách và bao gồm tất cả những gì cần thiết, thì thứ tự *include* chúng không quan trọng.

Bây giờ hãy xem xét tình huống sau: giả sử file header A cần các khai báo từ header B, nhưng quên *include* nó. Trong file code của chúng tôi, nếu chúng tôi include header B trước header A, code của chúng tôi vẫn sẽ biên dịch! Điều này là do trình biên dịch sẽ biên dịch tất cả các khai báo từ B trước khi nó biên dịch code từ A phụ thuộc vào các khai báo đó.

Tuy nhiên, nếu chúng tôi include header A trước tiên, thì trình biên dịch sẽ phàn nàn vì code từ A sẽ được biên dịch trước khi trình biên dịch thấy các khai báo từ B. Thực ra đây là điều đáng ưu tiên, vì lỗi đã được phát hiện và sau đó chúng ta có thể khắc phục nó.

>**Thực hành tốt nhất**<br>
>Để tối đa hóa khả năng các include bị thiếu sẽ được đánh dấu bởi trình biên dịch, hãy sắp xếp các #include của bạn như sau:
>1. File header được đính kèm (file header đi kèm với file code hiện tại)
>2. Các header khác từ project của bạn
>3. Header của thư viện của bên thứ ba (thư viện do người khác phát triển và bạn tích hợp vào project)
>4. Header của thư viện chuẩn (các header đi kèm với trình biên dịch C++)
>
>Các header cho mỗi nhóm nên được sắp xếp theo bảng chữ cái (trừ khi tài liệu cho thư viện của bên thứ ba hướng dẫn bạn làm khác).

Bằng cách đó, nếu một trong các header do bạn tự định nghĩa thiếu #include cho thư viện của bên thứ ba hoặc header của thư viện chuẩn, thì nó có nhiều khả năng gây ra lỗi biên dịch để bạn có thể khắc phục.



### **Các thực hành tốt nhất cho tệp tiêu đề**

Dưới đây là một vài đề xuất khác để tạo và sử dụng các tệp tiêu đề:

- Luôn luôn *include* **header guard** (chúng tôi sẽ đề cập đến chúng trong bài học tiếp theo). **Header guard** giúp ngăn ngừa việc *include* một file header nhiều lần trong cùng một unit code (chẳng hạn như một file cpp).
- Không định nghĩa biến và hàm trong các tệp header (trong bài học này).
- Đặt tên cho tệp header giống với tệp nguồn được liên kết với nó (ví dụ: grades.h được đính kèm với grades.cpp).
- Mỗi tệp header nên có một công việc cụ thể và độc lập nhất có thể. Ví dụ: bạn có thể đặt tất cả các khai báo liên quan đến chức năng A trong A.h và tất cả các khai báo liên quan đến chức năng B trong B.h. Bằng cách đó, nếu sau này bạn chỉ quan tâm đến A, bạn chỉ cần include A.h và không cần bất kỳ thứ gì liên quan đến B.
- Hãy chú ý đến các header bạn cần *include* rõ ràng cho các chức năng bạn đang sử dụng trong các file code của mình, để tránh *include* trung gian không cần thiết.
- Một file header nên `#include` bất kỳ header nào khác chứa các chức năng cần thiết. Header như vậy nên được biên dịch thành công khi được #include vào một file .cpp riêng lẻ.
- Chỉ *include* những gì bạn cần (không *include* tất cả mọi thứ chỉ vì bạn có thể).
- Không include các file .cpp.
- Ưu tiên đặt tài liệu về những gì đó hoạt động hoặc cách sử dụng nó trong header. Nó có nhiều khả năng được nhìn thấy ở đó. Tài liệu mô tả cách thức hoạt động của một thứ gì đó nên nằm trong các file nguồn.
