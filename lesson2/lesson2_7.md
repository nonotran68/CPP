## **Bài 2.7: <u>Tiền khai báo và Định nghĩa Hàm (Forward declarations and Definitions of Functions)</u>**

### **Giới thiệu:** 

Hãy xem xét chương trình mẫu có vẻ vô hại này:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Tổng của 3 và 4 là: " << add(3, 4) << '\n';
>    return 0;
>}
>
>int add(int x, int y)
>{
>    return x + y;
>}
>```

Bạn mong đợi chương trình này sẽ trả về kết quả:
>`Tổng của 3 và 4 là: 7`

Nhưng trên thực tế, nó không thể biên dịch được! Visual Studio tạo ra lỗi biên dịch sau:
>`add.cpp(5) : error C3861: 'add': identifier not found`

Đối với trình biên dịch GCC:
>```
>2_7notForwardDeclareFunc.cpp: In function ‘int main()’:
>2_7notForwardDeclareFunc.cpp:4:44: error: ‘add’ was not declared in 
>this scope
>    4 |     std::cout << "Tổng của 3 và 4 là: " << add(3,4) << '\n';
>      |                                            ^~~
>```


### **Xử lý vấn đề:** 

Để khắc phục sự cố này, chúng ta cần giải quyết vấn đề là trình biên dịch không biết `add` là gì. Có hai cách phổ biến để giải quyết vấn đề.

#### *<u>Cách 1: Sắp xếp lại định nghĩa hàm</u>*



Một cách để giải quyết vấn đề là sắp xếp lại các định nghĩa hàm để add được định nghĩa trước `main`:

>```
>#include <iostream>
>
>int add(int x, int y)
>{
>    return x + y;
>}
>
>int main()
>{
>    std::cout << "Tổng của 3 và 4 là: " << add(3, 4) << '\n';
>    return 0;
>}
>```

Bằng cách đó, vào thời điểm `main` gọi `add`, trình biên dịch sẽ đã biết `add` là gì. Bởi vì đây là một chương trình đơn giản nên việc thay đổi này tương đối dễ dàng thực hiện. Tuy nhiên, trong một chương trình lớn hơn, việc cố gắng tìm ra hàm nào gọi các hàm khác (và theo thứ tự nào) để chúng có thể được khai báo tuần tự có thể tốn nhiều công sức.

Hơn nữa, tùy chọn này không phải lúc nào cũng khả thi. Giả sử chúng ta đang viết một chương trình có hai hàm `A` và `B`. Nếu hàm `A` gọi hàm `B` và hàm `B` gọi hàm `A`, thì không có cách nào để sắp xếp các hàm theo cách làm cho trình biên dịch hài lòng. Nếu bạn định nghĩa `A` trước, trình biên dịch sẽ phàn nàn rằng nó không biết `B` là gì. Nếu bạn định nghĩa `B` trước, trình biên dịch sẽ phàn nàn rằng nó không biết `A` là gì.



#### *<u>Cách 2: Sử dụng tiền khai báo</u>*

Chúng ta cũng có thể khắc phục sự cố này bằng cách sử dụng tiền khai báo.

**Tiền khai báo (forward declaration)** cho phép chúng ta thông báo với trình biên dịch về sự tồn tại của một định danh trước khi thực sự định nghĩa định danh đó.

Đối với các hàm, điều này cho phép chúng ta thông báo với trình biên dịch về sự tồn tại của một hàm trước khi chúng ta định nghĩa thân hàm. Bằng cách này, khi trình biên dịch gặp phải một lệnh gọi đến hàm, nó sẽ hiểu rằng chúng ta đang thực hiện một lệnh gọi hàm và có thể kiểm tra để đảm bảo chúng ta đang gọi hàm chính xác, ngay cả khi nó chưa biết hàm được định nghĩa như thế nào hoặc ở đâu.

Để viết tiền khai báo cho một hàm, chúng ta sử dụng một câu lệnh khai báo hàm được gọi là **nguyên mẫu hàm**. **Nguyên mẫu hàm** bao gồm: **kiểu trả về, tên và kiểu tham số của hàm**, được kết thúc bằng **dấu chấm phẩy**. Tên của các tham số có thể tùy chọn. Thân hàm không được bao gồm trong khai báo.

Đây là nguyên mẫu hàm cho hàm `add`:

>```
>int add(int x, int y); // Nguyên mẫu hàm bao gồm kiểu trả về, tên, tham số và dấu chấm phẩy. Không có thân hàm!
>```


Ta sẽ sử dụng tiền khai báo để xử lí ví dụ ở đầu bài: 

>```
>#include <iostream>
>
>int add(int x, int y); // Tiền khai báo add() (sử dụng nguyên mẫu hàm)
>
>int main()
>{
>    std::cout << "Tổng của 3 và 4 là: " << add(3, 4) << '\n'; // Điều này hoạt động vì chúng ta đã viết tiền khai báo cho add() ở trên
>    return 0;
>}
>
>int add(int x, int y) // Mặc dù thân hàm của add() không được định nghĩa cho đến đây
>{
>    return x + y;
>}
>```

Bây giờ, khi trình biên dịch đến lệnh gọi `add` trong `main`, nó sẽ biết `add` trông như thế nào (một hàm nhận hai tham số kiểu số nguyên và trả về một giá trị kiểu số nguyên), và nó sẽ không phàn nàn.

Điều đáng chú ý là nguyên mẫu hàm không cần chỉ định tên của các tham số (vì chúng không được coi là một phần của khai báo hàm). Trong đoạn mã ở trên, bạn cũng có thể khai báo trước hàm của mình như thế này:

>`int add(int, int); // Khai báo hàm hợp lệ`

Tuy nhiên, chúng tôi thích đặt tên cho các tham số của mình (sử dụng cùng tên với hàm thực tế). Điều này cho phép bạn hiểu các tham số của hàm chỉ bằng cách nhìn vào khai báo. Ví dụ: nếu bạn nhìn thấy khai báo `void doSomething(int, int, int)`, bạn có thể nghĩ rằng bạn nhớ mỗi tham số đại diện cho cái gì, nhưng bạn cũng có thể hiểu sai.

Ngoài ra, nhiều công cụ tạo tài liệu tự động sẽ tạo tài liệu từ nội dung của các tệp header, đây là nơi các khai báo thường được đặt. Chúng tôi thảo luận về các tệp header và khai báo trong bài học **2.11 - Tệp header.**


>**Thực hành tốt nhất**<br>
>Giữ lại tên tham số trong tiền khai báo hàm của bạn.

>**Mẹo:**<br>
>Bạn có thể dễ dàng tạo các tiền khai báo hàm bằng cách sao chép/dán tiêu đề hàm của bạn và thêm dấu chấm phẩy.

### **Tại sao sử dụng tiền khai báo?**

Bạn có thể tự hỏi tại sao chúng ta lại sử dụng tiền khai báo nếu chúng ta có thể sắp xếp lại các hàm để làm cho chương trình của chúng ta hoạt động.

Thông thường, tiền khai báo được sử dụng để thông báo cho trình biên dịch về sự tồn tại của một số hàm được định nghĩa trong một tệp mã khác. Sắp xếp lại không thể thực hiện được trong trường hợp này vì hàm gọi và hàm được gọi nằm trong các tệp hoàn toàn khác nhau! Chúng tôi sẽ thảo luận về điều này chi tiết hơn trong bài học tiếp theo **(2.8 - Chương trình với nhiều tệp mã).**

Tiền khai báo cũng có thể được sử dụng để định nghĩa các hàm của chúng ta theo cách không phụ thuộc vào thứ tự. Điều này cho phép chúng ta định nghĩa các hàm theo bất kỳ thứ tự nào để tối đa hóa tổ chức (ví dụ: bằng cách nhóm các hàm liên quan lại với nhau) hoặc theo sự hiểu biết của người đọc.

Ít phổ biến hơn, có những trường hợp khi chúng ta có hai hàm gọi lẫn nhau. Sắp xếp lại cũng không thể thực hiện được trong trường hợp này, vì không có cách nào để sắp xếp lại các hàm sao cho mỗi hàm xuất hiện trước hàm kia. Tiền khai báo cung cấp cho chúng ta một cách để giải quyết các phụ thuộc theo vòng tròn như vậy.

### **Quên Thân Hàm**

Lập trình viên mới thường tự hỏi điều gì sẽ xảy ra nếu họ tiền khai báo một hàm nhưng không định nghĩa nó.

Câu trả lời là: phụ thuộc. Nếu tiền khai báo được thực hiện, nhưng hàm không bao giờ được gọi, chương trình sẽ biên dịch và chạy tốt. Tuy nhiên, nếu tiền khai báo được thực hiện và hàm được gọi, nhưng chương trình không bao giờ định nghĩa hàm, thì chương trình sẽ biên dịch ổn, nhưng trình liên kết sẽ phàn nàn rằng nó không thể giải quyết lệnh gọi hàm.

Xem xét chương trình sau:

>```
>#include <iostream>
>
>int add(int x, int y); // Khai báo trước add()
>
>int main()
>{
>    std::cout << "Tổng của 3 và 4 là: " << add(3, 4) << '\n';
>    return 0;
>}
>
>// Lưu ý: Không có định nghĩa cho hàm add
>```

Trong chương trình này, chúng tôi khai báo trước `add`, và chúng tôi gọi `add`, nhưng chúng tôi không bao giờ định nghĩa `add` ở bất kỳ đâu. Khi chúng tôi cố gắng biên dịch chương trình này, Visual Studio tạo ra thông báo sau:

>```
>Compiling...
>add.cpp
>Linking...
>add.obj : error LNK2001: unresolved external symbol "int __cdecl add(int,int)" (?add@@YAHHH@Z)
>add.exe : fatal error LNK1120: 1 unresolved externals
>```


Như bạn có thể thấy, chương trình đã được biên dịch bình thường, nhưng nó bị lỗi ở giai đoạn liên kết vì `int add(int, int)` không bao giờ được định nghĩa.

### **Các loại tiền khai báo khác**

Tiền khai báo thường được sử dụng nhất với các hàm. Tuy nhiên, tiền khai báo cũng có thể được sử dụng với các định danh khác trong C++, chẳng hạn như biến và kiểu dữ liệu. Biến và kiểu dữ liệu có cú pháp tiền khai báo khác nhau, vì vậy chúng tôi sẽ đề cập đến chúng trong các bài học sau.

### **Khai báo vs. Định nghĩa**

Trong C++, bạn sẽ thường xuyên nghe thấy các từ **"khai báo"** và **"định nghĩa"** được sử dụng, và thường được sử dụng thay thế cho nhau. Chúng có nghĩa là gì? Bây giờ bạn đã có đủ kiến thức cơ bản để hiểu sự khác biệt giữa hai điều này.

**Khai báo (declaration)** thông báo cho trình biên dịch về sự tồn tại của một định danh và thông tin kiểu liên quan của nó. Dưới đây là một số ví dụ về khai báo:
>```
>int add(int x, int y); // Thông báo cho trình biên dịch về một hàm có tên "add" nhận hai tham số kiểu int và trả về một kiểu int. Không có thân hàm!
>int x;                 // Thông báo cho trình biên dịch về một biến kiểu int có tên x
>```

**Định nghĩa (definition)** cung cấp cho trình biên dịch thông tin chi tiết về cách thức hoạt động của định danh. Nó bao gồm cả **khai báo** và **cung cấp phần thân (implementation)** của định danh. Phần thân cho trình biên dịch biết cách thực thi các hàm, khởi tạo biến, hoặc cấu trúc lớp.

>```
>int x = 10; // Định nghĩa biến `x` kiểu `int` và gán giá trị 10
>void printMessage() {
>  std::cout << "Hello, World!" << std::endl;
>}
>class Person {
>public:
>  std::string name;
>  int age;
>};
>```

Trong C++, tất cả định nghĩa đều là khai báo. Do đó `int x;` vừa là định nghĩa vừa là khai báo.

Ngược lại, không phải tất cả các khai báo đều là định nghĩa. Khai báo không phải là định nghĩa được gọi là **khai báo thuần túy (pure declaration)**. Các loại khai báo thuần túy bao gồm tiền khai báo cho hàm, biến và kiểu dữ liệu.

>**Thuật ngữ**<br>
>Trong ngôn ngữ thông thường, thuật ngữ **"khai báo"** thường được dùng để chỉ **"khai báo thuần túy"**, và **"định nghĩa"** được dùng để chỉ **"định nghĩa đồng thời là khai báo"**. Do đó, chúng ta thường gọi `int x;` là một định nghĩa, mặc dù nó vừa là định nghĩa vừa là khai báo.

Khi trình biên dịch gặp một định danh, nó sẽ kiểm tra để đảm bảo việc sử dụng định danh đó hợp lệ (ví dụ: định danh đó nằm trong phạm vi, nó được sử dụng theo cách cú pháp hợp lệ, v.v.).

Trong hầu hết các trường hợp, khai báo là đủ để cho phép trình biên dịch đảm bảo định danh đang được sử dụng đúng cách. Ví dụ, khi trình biên dịch gặp lệnh gọi hàm `add(5, 6)`, nếu nó đã thấy khai báo cho `add(int, int)`, thì nó có thể xác nhận rằng `add` thực sự là một hàm nhận hai tham số kiểu `int`. Nó không cần thực sự thấy định nghĩa của hàm `add` (có thể nằm trong một tệp khác).

Tuy nhiên, có một vài trường hợp trình biên dịch phải có thể nhìn thấy định nghĩa đầy đủ để sử dụng một định danh (chẳng hạn như đối với định nghĩa **khuôn mẫu (template)** và định nghĩa **kiểu dữ liệu**, cả hai đều sẽ được thảo luận trong các bài học sau).

**Tóm lại:**
- Khai báo chỉ thông báo cho trình biên dịch về sự tồn tại của một định danh.
- Định nghĩa cung cấp cho trình biên dịch thông tin chi tiết về cách thức hoạt động của định danh.
- Định nghĩa bao gồm cả khai báo.

**Lưu ý:**

- Không phải tất cả các định danh đều cần được định nghĩa. Ví dụ, bạn có thể tiền khai báo một hàm mà không cần định nghĩa nó, và trình biên dịch sẽ cho phép bạn sử dụng tên hàm trong biểu thức. Tuy nhiên, bạn sẽ không thể thực sự gọi hàm cho đến khi nó được định nghĩa.
- Trong một số trường hợp, bạn có thể thấy các thuật ngữ **"khai báo nguyên mẫu" (prototype declaration)** và **"khai báo hàm" (function declaration)** được sử dụng thay thế cho nhau. Cả hai đều đề cập đến việc khai báo một hàm mà không cung cấp phần thân của nó.

### **Quy tắc định nghĩa một lần (One definition rule hay ODR)**
 

**Quy tắc định nghĩa một lần (ODR)** là một quy tắc nổi tiếng trong C++. **ODR** có ba phần:
- **Trong một tệp:** Mỗi hàm, biến, kiểu hoặc khuôn mẫu chỉ có thể có một định nghĩa. Các định nghĩa xuất hiện trong các phạm vi khác nhau (ví dụ: biến cục bộ được định nghĩa bên trong các hàm khác nhau hoặc hàm được định nghĩa bên trong các không gian tên khác nhau) không vi phạm quy tắc này.
- **Trong một chương trình:** Mỗi hàm hoặc biến chỉ có thể có một định nghĩa. Quy tắc này tồn tại vì các chương trình có thể có nhiều hơn một tệp (chúng tôi sẽ đề cập đến điều này trong bài học tiếp theo). Các hàm và biến không hiển thị với trình liên kết bị loại trừ khỏi quy tắc này (được thảo luận thêm trong bài học **7.6 - Liên kết nội bộ**).
- **Kiểu, mẫu, hàm nội tuyến và biến nội tuyến** được phép có các định nghĩa trùng lặp trong các tệp khác nhau, miễn là mỗi định nghĩa đều giống hệt nhau. Chúng tôi chưa đề cập đến hầu hết những thứ này, vì vậy đừng lo lắng về điều này ngay bây giờ - chúng tôi sẽ quay lại vấn đề này khi nó có liên quan.

**Vi phạm phần 1** của ODR sẽ khiến trình biên dịch thông báo lỗi định nghĩa lại. **Vi phạm phần 2** của ODR sẽ khiến trình liên kết thông báo lỗi định nghĩa lại. **Vi phạm phần 3** của ODR sẽ dẫn đến hành vi bất định.

Đây là một ví dụ về việc vi phạm phần 1:

>```
>int add(int x, int y)
>{
>     return x + y;
>}
>
>int add(int x, int y) // Vi phạm ODR, chúng ta đã định nghĩa hàm add(int, int)
>{
>     return x + y;
>}
>
>int main()
>{
>    int x{};
>    int x{ 5 }; // Vi phạm ODR, chúng ta đã định nghĩa x
>}
>```

Trong ví dụ này, hàm `add(int, int)` được định nghĩa hai lần (trong phạm vi toàn cục) và biến cục bộ `int x` được định nghĩa hai lần (trong phạm vi của `main()`). Do đó, trình biên dịch Visual Studio thông báo các lỗi biên dịch sau:

>```
>project3.cpp(9): error C2084: function 'int add(int,int)' already has a body
>project3.cpp(3): note: see previous definition of 'add'
>project3.cpp(16): error C2086: 'int x': redefinition
>project3.cpp(15): note: see declaration of 'x'
>```

Tuy nhiên, việc `main()` có biến cục bộ được định nghĩa là `int x` và `add()` cũng có tham số hàm được định nghĩa là `int x` thì không phải là vi phạm ODR phần 1. Các định nghĩa này xảy ra trong các phạm vi khác nhau (trong phạm vi của mỗi hàm tương ứng), vì vậy chúng được coi là các định nghĩa riêng biệt cho hai đối tượng riêng biệt, không phải là định nghĩa và định nghĩa lại của cùng một đối tượng.

>**Đối với người đọc nâng cao**<br>
>Các hàm có cùng một định danh nhưng có các bộ tham số khác nhau cũng được coi là các hàm riêng biệt, vì vậy các định nghĩa như vậy không vi phạm ODR. Chúng tôi sẽ thảo luận thêm về điều này trong bài học **11.1 - Giới thiệu về nạp chồng hàm**.


