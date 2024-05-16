## **Bài 2.10: <u>Giới thiệu về bộ tiền xử lí (Preprocessor)</u>**



Khi bạn biên dịch dự án của mình, bạn có thể mong đợi trình biên dịch sẽ biên dịch từng tệp mã chính xác như những gì bạn đã viết. Thực tế không phải như vậy.

Thay vào đó, trước khi biên dịch, mỗi tệp mã nguồn (.cpp) đều trải qua giai đoạn **tiền xử lý (preprocessing)**. Trong giai đoạn này, một chương trình gọi là **preprocessor (bộ tiền xử lý)** thực hiện các thay đổi khác nhau đối với văn bản của tệp mã. **Bộ tiền xử lí** không thực sự sửa đổi các tệp mã gốc theo bất kỳ cách nào - thay vào đó, tất cả các thay đổi do **bộ tiền xử lí** thực hiện đều diễn ra tạm thời trong bộ nhớ hoặc sử dụng các tệp tạm thời.

>**Ngoài lề**<br>
>Trong lịch sử, preprocessor là một chương trình riêng biệt với trình biên dịch, nhưng trong các trình biên dịch hiện đại, preprocessor có thể được tích hợp ngay vào chính trình biên dịch.

Hầu hết những gì bộ tiền xử lí làm đều khá nhàm chán. **Ví dụ:** nó loại bỏ các chú thích và đảm bảo mỗi tệp mã kết thúc bằng một dòng mới. Tuy nhiên, bộ tiền xử lí có một vai trò rất quan trọng: nó là thứ xử lý các chỉ thị **`#include`** (chúng ta sẽ thảo luận thêm về điều này sau đây một lát).

Khi bộ tiền xử lí hoàn thành việc xử lý một tệp mã, kết quả thu được gọi là một **đơn vị dịch (translation unit)**. Đơn vị dịch này sau đó được biên dịch bởi trình biên dịch.

>**Nội dung liên quan**<br>
>Toàn bộ quá trình tiền xử lý, biên dịch và liên kết được gọi là **dịch (translation)**.
>
>Nếu bạn tò mò, đây là danh sách [các giai đoạn dịch](https://en.cppreference.com/w/cpp/language/translation_phases). Tính đến thời điểm viết bài này, tiền xử lý bao gồm các giai đoạn từ 1 đến 4, và biên dịch là các giai đoạn từ 5 đến 7.



### **Chỉ thị tiền xử lí (preprocessor directive)**

Khi bộ tiền xử lí chạy, nó quét qua tệp mã (từ trên xuống dưới), tìm kiếm các chỉ thị tiền xử lí. Chỉ thị tiền xử lí (thường được gọi tắt là chỉ thị) là các hướng dẫn bắt đầu bằng ký hiệu `#` và kết thúc bằng **một dòng mới** (**KHÔNG PHẢI** dấu chấm phẩy). Các chỉ thị này yêu cầu bộ tiền xử lí thực hiện một số tác vụ thao tác văn bản nhất định. Lưu ý rằng bộ tiền xử lí không hiểu cú pháp C++ - thay vào đó, các chỉ thị có cú pháp riêng của chúng (trong một số trường hợp giống với cú pháp C++ và trong một số trường hợp khác thì không).

Trong bài học này, chúng ta sẽ xem xét một số chỉ thị tiền xử lí phổ biến nhất.

>**Ngoài lề**<br>
>Chỉ thị bằng `using` (giới thiệu trong bài học **[2.9 - Xung đột tên và Giới thiệu về không gian tên](lesson2_9.ipynb)**) không phải là chỉ thị tiền xử lí (và do đó không được proprocessor xử lý). Vì vậy, mặc dù thuật ngữ *directive* thường có nghĩa là *preprocessor directive*, nhưng đây không phải lúc nào cũng đúng.

### **`#Include`** 

Bạn đã thấy chỉ thị `#include` được sử dụng (thường để `#include <iostream>`). Khi bạn `#include` một tệp, preprocessor sẽ thay thế chỉ thị `#include` bằng nội dung của tệp được *include*. Sau đó, nội dung được *include* sẽ được tiền xử lý (có thể dẫn đến việc các `#include` bổ sung được xử lý đệ quy), sau đó phần còn lại của tệp được tiền xử lí.

**Xem xét chương trình sau:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Hello, world!\n";
>    return 0;
>}

Khi bộ tiền xử lí chạy trên chương trình này, nó sẽ thay thế `#include <iostream>` bằng nội dung của tệp có tên **"`iostream`"** và sau đó xử lý trước nội dung được include rồi đến phần còn lại của tệp.

Khi bộ tiền xử lí hoàn thành việc xử lý tệp mã cùng với tất cả nội dung được `#include`, kết quả thu được gọi là một **đơn vị dịch (translation unit). Đơn vị dịch** là thứ được gửi đến trình biên dịch để được biên dịch.

>**Điểm mấu chốt**<br>
>Một đơn vị dịch bao gồm cả mã được xử lý từ tệp mã, cũng như mã được xử lý từ tất cả các tệp được `#include`.

Vì `#include` gần như chỉ được sử dụng để *include* các tệp `header`, chúng ta sẽ thảo luận chi tiết hơn về `#include` trong bài học tiếp theo (khi chúng ta thảo luận về các tệp `header`).

### **`#define`**

Chỉ thị `#define` có thể được sử dụng để tạo một **macro**. Trong C++, một **macro** là một quy tắc xác định cách văn bản đầu vào được chuyển đổi thành văn bản đầu ra thay thế.

Có hai loại macro cơ bản: **macro giống đối tượng** (object-like macro) và **macro giống hàm** (function-like macro).

**Macro giống hàm** hoạt động giống như các hàm và phục vụ mục đích tương tự. Việc sử dụng chúng thường được coi là không an toàn và hầu hết mọi thứ chúng có thể làm đều có thể được thực hiện bởi một hàm thông thường.

**Macro giống đối tượng** có thể được định nghĩa theo một trong hai cách:
>```
>#define IDENTIFIER
>#define IDENTIFIER substitution_text

Định nghĩa trên cùng không có văn bản thay thế, trong khi định nghĩa dưới cùng thì có. Do đây là các chỉ thị tiền xử lí (không phải câu lệnh), lưu ý rằng không có mẫu nào kết thúc bằng dấu chấm phẩy.

Định danh cho một macro sử dụng cùng các quy tắc đặt tên như các định danh thông thường: chúng có thể sử dụng các chữ cái, số và dấu gạch dưới, không thể bắt đầu bằng một số và không nên bắt đầu bằng dấu gạch dưới. Theo quy ước, tên macro thường được viết HOA, phân cách bằng dấu gạch dưới.

### **Macro giống đối tượng với văn bản thay thế**

Khi bộ tiền xử lí gặp phải chỉ thị này, bất kỳ sự xuất hiện tiếp theo của định danh sẽ được thay thế bằng *substitution_text* (văn bản thay thế). Theo truyền thống, định danh được viết HOA HẾT CHỮ CÁI, sử dụng dấu gạch dưới để biểu thị khoảng trắng.

**Xem xét chương trình sau:**
>```
>#include <iostream>
>
>#define MY_NAME "Alex"
>
>int main()
>{
>    std::cout << "My name is: " << MY_NAME << '\n';
>
>    return 0;
>}
>```

Bộ tiền xử lí sẽ chuyển đổi chương trình trên thành:
>```
>// Nội dung của iostream được chèn vào đây
>
>int main()
>{
>    std::cout << "My name is: " << "Alex" << '\n';
>    return 0;
>}
>```

Chạy chương trình này sẽ in ra kết quả `My name is: Alex`.

**Macro giống đối tượng với văn bản thay thế** đã từng được sử dụng (trong **C**) như một cách để gán tên cho các giá trị cố định (**literals**). Điều này không còn cần thiết nữa, vì **C++** cung cấp các phương thức tốt hơn. Macro giống đối tượng với văn bản thay thế thường chỉ nên xuất hiện trong *code cũ* (*legacy code*).

Chúng tôi khuyên bạn nên tránh hoàn toàn các loại macro này, vì có những cách tốt hơn để thực hiện những việc như vậy. Chúng tôi sẽ thảo luận thêm về điều này trong bài học **5.1 – Biến hằng (hằng được đặt tên)**.

### **Macro giống đối tượng không có văn bản thay thế** 

Macro giống đối tượng cũng có thể được định nghĩa mà không cần văn bản thay thế.

**Ví dụ:**
>```
>#define USE_YEN

Macro ở dạng này hoạt động như bạn mong đợi: bất kỳ sự xuất hiện tiếp theo của định danh sẽ bị loại bỏ và không được thay thế bằng gì cả!

Điều này có vẻ khá vô dụng, và nó thực sự vô dụng cho việc thay thế văn bản. Tuy nhiên, đây không phải là mục đích sử dụng thông thường của dạng chỉ thị này. Chúng ta sẽ thảo luận về cách sử dụng dạng này ngay sau đây.

Không giống như macro giống đối tượng với văn bản thay thế, macro dạng này thường được coi là chấp nhận được để sử dụng.

### **Biên dịch có điều kiện (Conditional compilation)**

Các chỉ thị tiền xử lý **biên dịch có điều kiện (conditional compilation)** cho phép bạn chỉ định điều kiện để một thứ gì đó được biên dịch hay không. Có khá nhiều chỉ thị tiền xử lý dịch thuật điều kiện khác nhau, nhưng chúng ta chỉ đề cập đến ba loại được sử dụng nhiều nhất ở đây: `#ifdef`, `#ifndef` và `#endif`.

Chỉ thị tiền xử lý `#ifdef` cho phép bộ tiền xử lí kiểm tra xem một định danh đã được `#defined` trước đó chưa. Nếu có, mã giữa `#ifdef` và `#endif` tương ứng sẽ được biên dịch. Ngược lại, mã sẽ bị bỏ qua.

**Xem xét chương trình sau:**
>```
>#include <iostream>
>
>#define PRINT_JOE
>
>int main()
>{
>#ifdef PRINT_JOE
>    std::cout << "Joe\n"; // sẽ được biên dịch vì PRINT_JOE được định nghĩa
>#endif
>
>#ifdef PRINT_BOB
>    std::cout << "Bob\n"; // sẽ bị loại trừ vì PRINT_BOB không được định nghĩa
>#endif
>
>    return 0;
>}
>```

Vì `PRINT_JOE` đã được `#define`, dòng `std::cout << "Joe\n"` sẽ được biên dịch. Vì `PRINT_BOB` chưa được `#define`, dòng `std::cout << "Bob\n"` sẽ bị bỏ qua.

`#ifndef` là ngược lại với `#ifdef`, nó cho phép bạn kiểm tra xem một định danh đã KHÔNG được `#defined` hay chưa.

>```
>#include <iostream>
>
>int main()
>{
>#ifndef PRINT_BOB
>    std::cout << "Bob\n";
>#endif
>
>    return 0;
>}
>```

Chương trình này in ra "`Bob`", bởi vì `PRINT_BOB` chưa bao giờ được `#defined`.

Thay cho `#ifdef PRINT_BOB` và `#ifndef PRINT_BOB`, bạn cũng sẽ thấy `#if defined(PRINT_BOB)` và `#if !defined(PRINT_BOB)`. Chúng hoạt động giống nhau, nhưng sử dụng cú pháp theo phong cách C++ hơn một chút.

### **`#if 0`**

Một cách sử dụng phổ biến khác của chỉ thị biên dịch điều kiện liên quan đến việc sử dụng `#if 0` để loại trừ một khối mã khỏi việc được biên dịch (giống như thể nó nằm bên trong một khối chú thích):

>```
>#include <iostream>
>
>int main()
>{
>  std::cout << "Joe\n";
>
>#if 0 // Bỏ qua mọi thứ bắt đầu từ đây
>  std::cout << "Bob\n";
>  std::cout << "Steve\n";
>#endif // cho đến điểm này
>
>  return 0;
>}
>```

Đoạn mã ở trên chỉ in ra "`Joe`", vì "`Bob`" và "`Steve`" bị loại trừ khỏi quá trình biên dịch bởi chỉ thị tiền xử lý `#if 0`.

Điều này cung cấp một cách thuận tiện để "chú thích" ra mã chứa các chú thích nhiều dòng (không thể được chú thích ra bằng cách sử dụng một chú thích nhiều dòng khác do các chú thích nhiều dòng không thể lồng nhau):
>```
>#include <iostream>
>
>int main()
>{
>  std::cout << "Joe\n";
>
>#if 0 // Bỏ qua mọi thứ bắt đầu từ đây
>  std::cout << "Bob\n";
>  /* Một số
>   * chú thích nhiều dòng
>   * ở đây
>   */
>  std::cout << "Steve\n";
>#endif // cho đến điểm này
>
>  return 0;
>}
>```

Để bật lại tạm thời mã đã được bọc trong `#if 0`, bạn có thể đổi `#if 0` thành `#if 1`:
>```
>#include <iostream>
>
>int main()
>{
>  std::cout << "Joe\n";
>
>#if 1 // luôn đúng, vì vậy mã sau đây sẽ được biên dịch
>  std::cout << "Bob\n";
>  /* Một số
>   * chú thích nhiều dòng
>   * ở đây
>   */
>  std::cout << "Steve\n";
>#endif
>
>  return 0;
>}
>```

### **Macro giống đối tượng không ảnh hưởng đến các chỉ thị tiền xử lý khác**

Bây giờ bạn có thể đang tự hỏi:
>```
>#define PRINT_JOE
>
>#ifdef PRINT_JOE
>// ...
>```

Vì chúng ta đã định nghĩa `PRINT_JOE` thành một giá trị rỗng, tại sao bộ tiền xử lí không thay thế `PRINT_JOE` trong `#ifdef PRINT_JOE` thành giá trị rỗng?

Macro chỉ gây ra việc thay thế văn bản cho các lệnh không phải là lệnh tiền xử lý. Vì `#ifdef PRINT_JOE` là một lệnh tiền xử lý, nên việc thay thế văn bản không áp dụng cho `PRINT_JOE` trong lệnh này.

**Một ví dụ khác:**

>```
>#define FOO 9 // Đây là chỉ thị macro
>
>#ifdef FOO // FOO này không bị thay thế vì nó là một phần của một chỉ thị tiền xử lý khác
>    std::cout << FOO << '\n'; // FOO này được thay thế thành 9 vì nó là một phần của mã thông thường
>#endif
>```

Tuy nhiên, đầu ra cuối cùng của bộ tiền xử lí không chứa bất kỳ chỉ thị nào cả - tất cả chúng đều được xử lí/loại bỏ trước khi biên dịch, vì trình biên dịch sẽ không biết phải làm gì với chúng.

### **Phạm vi của `#define`**

Các chỉ thị được xử lí trước khi biên dịch, từ trên xuống dưới trên cơ sở từng tệp.

**Xét chương trình sau:**
>```
>#include <iostream>
>
>void foo()
>{
>#define MY_NAME "Alex"
>}
>
>int main()
>{
>	std::cout << "My name is: " << MY_NAME << '\n';
>
>	return 0;
>}
>```

Mặc dù trông giống như `#define MY_NAME "Alex"` được định nghĩa bên trong hàm `foo`, nhưng bộ tiền xử lí sẽ không nhận thấy, vì nó không hiểu các khái niệm C++ như hàm. Do đó, chương trình này hoạt động giống hệt như chương trình có `#define MY_NAME "Alex"` được định nghĩa trước hoặc ngay sau hàm foo. Để dễ đọc, bạn thường sẽ muốn `#define` các định danh bên ngoài các hàm.

Sau khi bộ tiền xử lí chạy xong, tất cả các định danh được định nghĩa từ tệp đó sẽ bị loại bỏ. Điều này có nghĩa là các chỉ thị chỉ có giá trị từ điểm định nghĩa đến cuối tệp mà chúng được định nghĩa. Các chỉ thị được định nghĩa trong một tệp mã không ảnh hưởng đến các tệp mã khác trong cùng một dự án.

**Xem xét ví dụ sau:**

**function.cpp:**
>```
>#include <iostream>
>
>void doSomething()
>{
>#ifdef PRINT
>    std::cout << "Printing!\n";
>#endif
>#ifndef PRINT
>    std::cout << "Not printing!\n";
>#endif
>}
>```

**main.cpp:**
>```
>void doSomething(); // Khai báo trước cho hàm doSomething()
>
>#define PRINT
>
>int main()
>{
>    doSomething();
>
>    return 0;
>}
>```

Chương trình trên sẽ in ra:
>`Not printing!`

Mặc dù `PRINT` đã được định nghĩa trong `main.cpp`, điều đó không ảnh hưởng đến bất kỳ mã nào trong `function.cpp` (`PRINT` chỉ được `#define` từ điểm định nghĩa đến cuối tệp `main.cpp`). Điều này sẽ có hậu quả khi chúng ta thảo luận về các **header guard** trong bài học sắp tới.
