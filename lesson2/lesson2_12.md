## **Bài 2.12: <u>Bộ bảo vệ tiêu đề (Header guards)</u>**

### **Vấn đề định nghĩa trùng lặp** 

Trong bài học [**2.7 - Tiền khai báo và định nghĩa hàm**](lesson2_7.ipynb), chúng tôi đã lưu ý rằng một định danh biến hoặc hàm chỉ có thể có một định nghĩa (quy tắc ODR). Do đó, một chương trình định nghĩa một định danh biến nhiều hơn một lần sẽ gây ra lỗi biên dịch:
>```
>int main()
>{
>    int x; // đây là định nghĩa cho biến x
>    int x; // lỗi biên dịch: định nghĩa trùng lặp
>
>    return 0;
>}
>```

Tương tự, các chương trình định nghĩa một hàm nhiều hơn một lần cũng sẽ gây ra lỗi biên dịch:
>```
>#include <iostream>
>
>int foo() // this is a definition for function foo
>{
>    return 5;
>}
>
>int foo() // compile error: duplicate definition
>{
>    return 5;
>}
>
>int main()
>{
>    std::cout << foo();
>    return 0;
>}
>```

Mặc dù các chương trình này có thể dễ dàng sửa chữa (xóa định nghĩa trùng lặp), nhưng với các tệp tiêu đề, thì việc kết thúc trong tình huống định nghĩa trong tệp tiêu đề được *include* nhiều hơn một lần là khá dễ gặp. Điều 
này có thể xảy ra khi một tệp tiêu đề `#include` một tệp tiêu đề khác (điều này thường gặp).

>**Lưu ý của tác giả**<br>
>Trong các ví dụ sắp tới, chúng tôi sẽ định nghĩa một số hàm bên trong các tệp tiêu đề. Bạn thường không nên làm điều này.
>
>Chúng tôi đang làm như vậy ở đây vì nó là cách hiệu quả nhất để mô tả một số khái niệm bằng cách sử dụng chức năng mà chúng tôi đã đề cập.

**Xem xét ví dụ học tập sau:**

**square.h:**
>```
>int getSquareSides();
>{
>    return 4;
>}
>```

**wave.h:**
>```
>#include "square.h"

**main.cpp:**
>```
>#include "square.h"
>#include "wave.h"
>
>int main()
>{
>    return 0;
>}
>```

Chương trình trông có vẻ vô hại này sẽ không được biên dịch! Đây là những gì đang xảy ra. Đầu tiên, `main.cpp` `#include` `square.h`, sao chép định nghĩa cho hàm `getSquareSides` vào `main.cpp`. Sau đó `main.cpp` `#include` `wave.h`, tệp mà sẽ tự `#include` trở lại `square.h`. Nó sao chép nội dung của `square.h` (bao gồm định nghĩa cho hàm `getSquareSides`) vào `wave.h`, sau đó được sao chép vào `main.cpp`.

Do đó, sau khi giải quyết tất cả các `#include`, `main.cpp` sẽ trông giống như thế này:
>```
>int getSquareSides()  // từ square.h
>{
>    return 4;
>}
>
>int getSquareSides() // từ wave.h (qua square.h)
>{
>    return 4;
>}
>
>int main()
>{
>    return 0;
>} 
>```

Định nghĩa trùng lặp và xuất hiện lỗi biên dịch. Mỗi tệp, riêng lẻ, đều ổn. Tuy nhiên, vì `main.cpp` `#include` nội dung của `square.` hai lần, nên chúng ta đã gặp phải vấn đề. Nếu `wave.h` cần `getSquareSides()`, và `main.cpp` cần cả `wave.h` và `square.h`, bạn sẽ giải quyết vấn đề này như thế nào?


### **Bộ bảo vệ tiêu đề (Header guards)**

Tin tốt là chúng ta có thể tránh được vấn đề trên thông qua một cơ chế gọi là **header guard** (còn được gọi là **include guard**). **Header guard** là các chỉ thị biên dịch có điều kiện với dạng như sau:
>```
>#ifndef SOME_UNIQUE_NAME_HERE
>#define SOME_UNIQUE_NAME_HERE
>
>// Các khai báo (và một số loại định nghĩa) của bạn ở đây
>
>#endif

Khi tệp tiêu đề này được `#include`, bộ tiền xử lý kiểm tra xem `SOME_UNIQUE_NAME_HERE` đã được định nghĩa trước đó chưa. Nếu đây là lần đầu tiên chúng ta include header, `SOME_UNIQUE_NAME_HERE` sẽ chưa được định nghĩa. Do đó, nó sẽ `#define SOME_UNIQUE_NAME_HERE` và bao gồm nội dung của tệp. Nếu header được *include* lại vào cùng một tệp, `SOME_UNIQUE_NAME_HERE` sẽ đã được định nghĩa từ lần đầu tiên nội dung của header được *include* và nội dung của header sẽ bị bỏ qua (nhờ `#ifndef`).

Tất cả các tệp tiêu đề của bạn nên có **header guard**. `SOME_UNIQUE_NAME_HERE` có thể là bất kỳ tên nào bạn muốn, nhưng theo quy ước được đặt thành tên tệp đầy đủ của tệp tiêu đề, được VIẾT HOA MỌI CHỮ, sử dụng dấu gạch dưới cho khoảng trắng hoặc dấu câu. Ví dụ: `square.h` sẽ có header guard: 

**square.h:**
>```
>#ifndef SQUARE_H
>#define SQUARE_H
>
>int getSquareSides();
>{
>    return 4;
>}
>#endif
>```

Ngay cả các header của thư viện chuẩn cũng sử dụng header guard. Nếu bạn xem qua tệp header `iostream` từ Visual Studio, bạn sẽ thấy:

>```
>#ifndef _IOSTREAM_
>#define _IOSTREAM_
>
>// nội dung ở đây
>
>#endif
>```

>**Đối với độc giả nâng cao**<br>
>Trong các chương trình lớn, có thể có hai tệp header riêng biệt (được *include* từ các thư mục khác nhau) có cùng tên tệp (ví dụ: *directoryA/config.h* và *directoryB/config.h*). Nếu chỉ sử dụng tên tệp cho include guard (ví dụ: `CONFIG_H`), hai tệp này có thể sử dụng cùng một tên guard. Nếu điều đó xảy ra, bất kỳ tệp nào *include* (trực tiếp hoặc gián tiếp) cả hai tệp *config.h* sẽ không nhận được nội dung của tệp tiêu đề được *include* thứ hai. Điều này có thể gây ra lỗi biên dịch.
>
>Do khả năng xảy ra xung đột tên guard, nhiều nhà phát triển khuyên bạn nên sử dụng tên phức tạp/độc nhất hơn trong header guard của mình. Một số gợi ý hay là quy ước đặt tên `PROJECT_PATH_FILE_H`, `FILE_LARGE-RANDOM-NUMBER_H` hoặc `FILE_CREATION-DATE_H`.



### **Cập nhật ví dụ trước đó của chúng tôi với header guard**

Hãy quay lại ví dụ `square.h`, sử dụng `square.h` với header guard. Để hay, chúng tôi cũng sẽ thêm header guard vào `wave.h`.

**square.h**
>```
>#ifndef SQUARE_H
>#define SQUARE_H
>
>int getSquareSides()
>{
>    return 4;
>}
>
>#endif
>```

**wave.h**
>```
>#ifndef WAVE_H
>#define WAVE_H
>
>#include "square.h"
>
>#endif
>```

**main.cpp**
>```
>#include "square.h"
>#include "wave.h"
>
>int main()
>{
>    return 0;
>}
>```

Sau khi bộ tiền xử lý giải quyết tất cả các lệnh `#include`, chương trình này trông giống như thế này:

**main.cpp**
>```
>// Square.h included from main.cpp
>#ifndef SQUARE_H  // square.h included from main.cpp
>#define SQUARE_H  // SQUARE_H được định nghĩa ở đây
>
>// và tất cả nội dung này được include
>int getSquareSides()
>{
>    return 4;
>}
>
>#endif  // SQUARE_H
>
>#ifndef WAVE_H  // wave.h included from main.cpp
>#define WAVE_H
>#ifndef SQUARE_H  // square.h included from wave.h, SQUARE_H đã được định nghĩa ở trên
>#define SQUARE_H  // vì vậy không có nội dung nào trong số này được include
>
>int getSquareSides()
>{
>    return 4;
>}
>
>#endif  // SQUARE_H
>#endif  // WAVE_H
>
>int main()
>{
>    return 0;
>}
>```

Hãy xem cách nó được đánh giá.

Đầu tiên, bộ tiền xử lý đánh giá `#ifndef SQUARE_H`. `SQUARE_H` chưa được định nghĩa, vì vậy mã từ `#ifndef` đến `#endif` tiếp theo được `include` để biên dịch. Mã này định nghĩa `SQUARE_H` và có định nghĩa cho hàm `getSquareSides`.

Sau đó, `#ifndef SQUARE_H` tiếp theo được đánh giá. Lần này, `SQUARE_H` được định nghĩa (vì nó đã được định nghĩa ở trên), do đó mã từ `#ifndef` đến `#endif` tiếp theo bị loại trừ khỏi quá trình biên dịch.

Header guard ngăn chặn các include trùng lặp vì lần đầu tiên gặp guard, macro guard chưa được định nghĩa, do đó nội dung được bảo vệ được *include*. Sau điểm đó, macro guard được định nghĩa, vì vậy bất kỳ bản sao nào sau đó của nội dung được bảo vệ đều bị loại trừ.

### **Header guard không ngăn chặn tệp tiêu đề được include một lần vào các tệp mã khác nhau**

Lưu ý rằng mục tiêu của header guard là ngăn chặn một tệp code nhận được nhiều hơn một bản sao của header được bảo vệ. Theo thiết kế, header guard không ngăn chặn một tệp header nhất định được *include* (một lần) vào các file code riêng biệt. Điều này cũng có thể gây ra các vấn đề bất ngờ. Xem xét:

**square.h:**
>```
>#ifndef SQUARE_H
>#define SQUARE_H
>
>int getSquareSides();
>{
>    return 4;
>}
>
>int getSquarePerimeter(int sideLength); // khai báo trước cho getSquarePerimeter
>
>#endif
>```

**square.cpp:**
>```
>#include "square.h"  // square.h được include một lần ở đây
>
>int getSquarePerimeter(int sideLength)
>{
>    return sideLength * getSquareSides();
>}
>```

**main.cpp:**
>```
>#include "square.h" // square.h cũng được include một lần ở đây
>#include <iostream>
>
>int main()
>{
>    std::cout << "a square has " << getSquareSides() << " sides\n";
>    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';
>
>    return 0;
>}
>```

Lưu ý rằng `square.h` được *include* từ cả `main.cpp` và `square.cpp`. Điều này có nghĩa là nội dung của `square.h` sẽ được *include* một lần vào `square.cpp` và một lần vào `main.cpp`.

Chúng ta hãy kiểm tra chi tiết hơn lý do tại sao điều này xảy ra. Khi `square.h` được *include* từ `square.cpp`, `SQUARE_H` được định nghĩa cho đến cuối `square.cpp`. Định nghĩa này ngăn `square.h` được *include* vào `square.cpp` lần thứ hai (đó là điểm của header guard). Tuy nhiên, một khi `square.cpp` hoàn thành, `SQUARE_H` không còn được coi là được định nghĩa nữa. Điều này có nghĩa là khi bộ tiền xử lý chạy trên `main.cpp`, `SQUARE_H` không được định nghĩa ban đầu trong `main.cpp`.

Kết quả cuối cùng là cả `square.cpp` và `main.cpp` đều có một bản sao của định nghĩa `getSquareSides`. Chương trình này sẽ được biên dịch, nhưng trình liên kết sẽ phàn nàn về việc chương trình của bạn có nhiều định nghĩa cho định danh `getSquareSides`!

Cách tốt nhất để giải quyết vấn đề này là chỉ cần đặt định nghĩa hàm trong một trong các file .cpp để header chỉ chứa khai báo trước:

**square.h:**
>```
>#ifndef SQUARE_H
>#define SQUARE_H
>
>int getSquareSides(); // khai báo trước cho getSquareSides
>int getSquarePerimeter(int sideLength); // khai báo trước cho getSquarePerimeter
>
>#endif
>```

**square.cpp:**

>```
>#include "square.h"
>
>int getSquareSides() // định nghĩa thực tế cho getSquareSides
>{
>    return 4;
>}
>
>int getSquarePerimeter(int sideLength)
>{
>    return sideLength * getSquareSides();
>}
>```

**main.cpp:**
>```
>#include "square.h" // square.h cũng được include một lần ở đây
>#include <iostream>
>
>int main()
>{
>    std::cout << "a square has " << getSquareSides() << " sides\n";
>    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';
>
>    return 0;
>}
>```

Bây giờ khi chương trình được biên dịch, hàm `getSquareSides` sẽ chỉ có một định nghĩa (thông qua `square.cpp`), vì vậy trình liên kết hoạt động bình thường. File `main.cpp` có thể gọi hàm này (mặc dù nó nằm trong `square.cpp`) vì nó *include* `square.h`, chứa khai báo trước cho hàm (trình liên kết sẽ kết nối cuộc gọi đến `getSquareSides` từ `main.cpp` với định nghĩa của `getSquareSides` trong `square.cpp`).



### **Không phải chúng ta chỉ cần tránh định nghĩa trong các tệp tiêu đề là được thôi sao?**

Chúng tôi thường khuyên bạn không nên chèn định nghĩa hàm trong header. Vì vậy, bạn có thể tự hỏi tại sao bạn nên *include* **header guard** nếu chúng bảo vệ bạn khỏi thứ bạn không nên làm.

Sẽ có một vài trường hợp mà chúng tôi sẽ chỉ cho bạn trong tương lai, nơi cần thiết phải đặt các định nghĩa không phải hàm trong tệp tiêu đề. Ví dụ, **C++** cho phép bạn tạo các kiểu dữ liệu của riêng bạn. Các kiểu dữ liệu tùy chỉnh này thường được định nghĩa trong các tệp tiêu đề, vì vậy định nghĩa kiểu dữ liệu có thể được truyền ra các tệp code cần sử dụng chúng. Nếu không có header guard, một tệp code có thể kết thúc với nhiều bản sao (giống hệt nhau) của định nghĩa kiểu dữ liệu nhất định, điều này sẽ khiến trình biên dịch báo lỗi.

Vì vậy, mặc dù việc có header guard không hoàn toàn cần thiết ở giai đoạn này của loạt bài hướng dẫn, chúng tôi đang thiết lập những thói quen tốt ngay bây giờ, để bạn không phải học lại những thói quen xấu sau này.

### **`#pragma once`**

Các trình biên dịch hiện đại hỗ trợ một dạng **header guard** đơn giản hơn, thay thế bằng cách sử dụng chỉ thị tiền xử lý `#pragma`:
>```
>#pragma once
>
>// code của bạn ở đây
>```

`#pragma once` phục vụ cùng mục đích với **header guard**: để tránh một file header được *include* nhiều lần. Với header guard truyền thống, developer chịu trách nhiệm bảo vệ header (bằng cách sử dụng các chỉ thị tiền xử lý `#ifndef`, `#define` và `#endif`). Với `#pragma once`, chúng tôi yêu cầu trình biên dịch bảo vệ header. Chính xác cách thực hiện điều này phụ thuộc vào từng trình biên dịch cụ thể.

>**Đối với độc giả nâng cao**<br>
>Có một trường hợp đã biết là `#pragma once` thường sẽ thất bại. Nếu một tệp header được sao chép để nó tồn tại ở nhiều vị trí khác nhau trên hệ thống file, nếu bằng cách nào đó cả hai bản sao của header đều được *include*, header guard sẽ loại bỏ trùng lặp thành công các header giống hệt nhau, nhưng `#pragma once` thì không (vì trình biên dịch sẽ không nhận ra chúng thực sự là nội dung giống hệt nhau).

Đối với hầu hết các dự án, `#pragma once` hoạt động tốt và nhiều developer hiện nay thích nó hơn vì nó dễ dàng hơn và ít lỗi hơn. Nhiều IDE cũng sẽ tự động include `#pragma once` ở đầu một file header mới được tạo thông qua IDE.

>**Cảnh báo**<br>
>Chỉ thị `#pragma` được thiết kế để người triển khai trình biên dịch sử dụng cho bất kỳ mục đích nào họ mong muốn. Do đó, các *pragma* được hỗ trợ và ý nghĩa của các *pragma* đó hoàn toàn phụ thuộc vào từng trình biên dịch cụ thể. Ngoại trừ `#pragma once`, đừng mong đợi một *pragma* hoạt động trên một trình biên dịch được hỗ trợ bởi một trình biên dịch khác.

Vì `#pragma once` không được tiêu chuẩn C++ định nghĩa, nên một số trình biên dịch có thể không triển khai nó (). Vì lý do này, một số công ty phát triển (chẳng hạn như Google) khuyên nên sử dụng header guard truyền thống. Trong loạt bài hướng dẫn này, chúng tôi sẽ ưu tiên header guard, vì chúng là cách thông dụng nhất để bảo vệ header. Tuy nhiên, hỗ trợ cho `#pragma once` hiện khá phổ biến và nếu bạn muốn sử dụng `#pragma once` thay thế, điều đó thường được chấp nhận trong C++ hiện đại.

### **Tóm tắt**

**Header guard** được thiết kế để đảm bảo nội dung của một tệp tiêu đề nhất định không được chép nhiều hơn một lần vào bất kỳ file riêng lẻ nào, nhằm tránh các định nghĩa trùng lặp.

**Khai báo trùng lặp (duplicate declarations)** là hoàn toàn ổn - nhưng ngay cả khi tệp tiêu đề của bạn chỉ toàn là khai báo (không có định nghĩa) thì việc sử dụng header guard vẫn là cách thực hành tốt nhất.

**Lưu ý** rằng header guard không ngăn chặn nội dung của tệp tiêu đề được *include* (một lần) vào các file dự án riêng biệt. Đây là điều tốt, vì chúng ta thường cần tham chiếu nội dung của một header nhất định từ các file dự án khác nhau.
