## **Bài 2.9: <u>Xung đột tên và giới thiệu về không gian tên (namespaces)</u>** 

**Tình huống**

Hãy tưởng tượng bạn đang lái xe đến nhà một người bạn lần đầu tiên, và địa chỉ được cung cấp là số 245 phố Front ở Mill City. Khi đến Mill City, bạn lấy bản đồ ra, chỉ để phát hiện ra rằng Mill City thực sự có hai phố Front khác nhau nằm cách xa nhau! Bạn sẽ đi đến cái nào? Trừ khi có một số gợi ý bổ sung để giúp bạn quyết định (ví dụ: bạn nhớ nhà bạn mình ở gần sông), bạn sẽ phải gọi cho bạn mình và yêu cầu thêm thông tin. Bởi vì điều này sẽ gây nhầm lẫn và kém hiệu quả (đặc biệt là đối với người đưa thư), ở hầu hết các quốc gia, tất cả tên đường và địa chỉ nhà trong một thành phố đều phải là duy nhất.

### **Xung đột tên trong C++** 

Tương tự, C++ yêu cầu tất cả các định danh (identifier) đều không được gây mù mờ. Nếu hai định danh giống hệt nhau được đưa vào cùng một chương trình theo cách mà trình biên dịch hoặc trình liên kết không thể phân biệt chúng, trình biên dịch hoặc trình liên kết sẽ tạo ra lỗi. Lỗi này thường được gọi là **xung đột tên** (hoặc **trùng tên**).

Nếu các định danh xung đột được đưa vào cùng một tệp, kết quả sẽ là lỗi trình biên dịch. Nếu các định danh xung đột được đưa vào các tệp riêng biệt thuộc cùng một chương trình, kết quả sẽ là lỗi trình liên kết.

**Ví dụ về xung đột tên**

**a.cpp:**

>```
>#include <iostream>
>
>void myFcn(int x) {
>  std::cout << x;
>}
>```

**main.cpp:**
>```
>#include <iostream>
>
>void myFcn(int x) {
>  std::cout << 2 * x;
>}
>
>int main() {
>  return 0;
>}
>```

Khi trình biên dịch biên dịch chương trình này, nó sẽ biên dịch `a.cpp` và `main.cpp` độc lập và mỗi tệp sẽ được biên dịch mà không có vấn đề gì.

Tuy nhiên, khi trình liên kết thực thi, nó sẽ liên kết tất cả các định nghĩa trong `a.cpp` và `main.cpp` lại với nhau và phát hiện ra các định nghĩa xung đột cho hàm `myFcn()`. Sau đó, trình liên kết sẽ dừng với lỗi. Lưu ý rằng lỗi này xảy ra ngay cả khi `myFcn()` không bao giờ được gọi!

**Các trường hợp phổ biến gây ra xung đột tên**

Hầu hết các xung đột tên xảy ra trong hai trường hợp:

- Hai (hoặc nhiều) hàm (hoặc biến toàn cục) có tên giống hệt nhau được đưa vào các tệp riêng biệt thuộc cùng một chương trình. Điều này sẽ dẫn đến lỗi trình liên kết, như được hiển thị ở trên.
- Hai (hoặc nhiều) hàm (hoặc biến toàn cục) có tên giống hệt nhau được đưa vào cùng một tệp. Điều này sẽ dẫn đến lỗi trình biên dịch.

Khi chương trình trở nên lớn hơn và sử dụng nhiều định danh hơn, khả năng xảy ra xung đột tên sẽ tăng lên đáng kể. Tin tốt là C++ cung cấp nhiều cơ chế để tránh xung đột tên. Phạm vi cục bộ, giúp các biến cục bộ được định nghĩa bên trong các hàm không xung đột với nhau, là một trong những cơ chế như vậy. Nhưng phạm vi cục bộ không hoạt động cho tên hàm. Vậy làm thế nào để chúng ta tránh tên hàm xung đột với nhau?

### **Vùng phạm vi (Scope Regions)**

Quay lại ví dụ về địa chỉ của chúng ta một chút, việc có hai con phố Front chỉ gây ra rắc rối vì những con phố đó nằm trong cùng một thành phố. Mặt khác, nếu bạn phải gửi thư đến hai địa chỉ, một địa chỉ tại số 245 phố Front ở Thành phố Mill và một địa chỉ khác tại số 417 phố Front ở Jonesville, thì sẽ không có nhầm lẫn về việc đi đến đâu. Nói cách khác, các thành phố cung cấp các nhóm cho phép chúng ta phân biệt các địa chỉ có thể xung đột với nhau.

Vùng phạm vi là một khu vực trong mã nguồn nơi tất cả các định danh được khai báo được coi là riêng biệt so với các tên được khai báo trong các vùng phạm vi khác (giống như các thành phố trong ví dụ của chúng ta). Hai định danh có cùng tên có thể được khai báo trong các vùng phạm vi riêng biệt mà không gây ra xung đột đặt tên. Tuy nhiên, trong một vùng phạm vi nhất định, tất cả các định danh phải duy nhất, nếu không sẽ dẫn đến xung đột đặt tên.

Thân hàm là một ví dụ về vùng phạm vi. Hai định danh có tên giống nhau có thể được định nghĩa trong các hàm riêng biệt mà không có vấn đề gì - bởi vì mỗi hàm cung cấp một vùng phạm vi riêng biệt, nên không có xung đột. Tuy nhiên, nếu bạn cố gắng định nghĩa hai định danh có tên giống nhau trong cùng một hàm, sẽ xảy ra xung đột đặt tên và trình biên dịch sẽ báo lỗi.

### **Không gian tên (Namespaces)**

Không gian tên cung cấp một loại vùng phạm vi khác (gọi là phạm vi không gian tên) cho phép bạn khai báo tên bên trong đó để phân biệt rõ ràng. Bất kỳ tên nào được khai báo bên trong không gian tên sẽ không bị nhầm lẫn với các tên giống hệt nhau trong các phạm vi khác.


>**Điểm mấu chốt**<br>
>Một tên được khai báo trong một vùng phạm vi (chẳng hạn như không gian tên) sẽ không bị nhầm lẫn với một tên giống hệt được khai báo trong một vùng phạm vi khác.

Không giống như các hàm (được thiết kế để chứa các câu lệnh có thể thực thi), chỉ các khai báo và định nghĩa mới có thể xuất hiện trong phạm vi của một không gian tên. Ví dụ, hai hàm có tên giống hệt nhau có thể được định nghĩa bên trong các không gian tên riêng biệt và sẽ không xảy ra xung đột đặt tên.

>**Điểm mấu chốt**<br>
>Chỉ các khai báo và định nghĩa mới có thể xuất hiện trong phạm vi của một không gian tên (không phải các câu lệnh có thể thực thi). Tuy nhiên, một hàm có thể được định nghĩa bên trong một không gian tên và hàm đó có thể chứa các câu lệnh có thể thực thi.

Không gian tên thường được sử dụng để nhóm các định danh liên quan trong một dự án lớn để giúp đảm bảo chúng không vô tình va chạm với các định danh khác. Ví dụ, nếu bạn đặt tất cả các hàm toán học của mình vào một không gian tên có tên math, thì các hàm toán học của bạn sẽ không xung đột với các hàm có tên giống hệt nhau bên ngoài không gian tên math.

Chúng ta sẽ thảo luận về cách tạo các không gian tên của riêng bạn trong một bài học sắp tới.

### **Không gian tên toàn cục (Global Namespace)** 

Trong C++, bất kỳ tên nào không được định nghĩa bên trong một lớp, hàm hoặc không gian tên nào khác đều được coi là một phần của một không gian tên được định nghĩa ngầm định, gọi là **không gian tên toàn cục** (đôi khi còn được gọi là **phạm vi toàn cục**).

Trong ví dụ ở đầu bài học, các hàm `main()` và cả hai phiên bản của `myFcn()` đều được định nghĩa bên trong không gian tên toàn cục. Xung đột đặt tên gặp phải trong ví dụ xảy ra vì cả hai phiên bản của `myFcn()` đều nằm trong không gian tên toàn cục, điều này vi phạm quy tắc là tất cả các tên trong vùng phạm vi phải là duy nhất.

Chúng tôi sẽ thảo luận chi tiết hơn về không gian tên toàn cục trong bài học **7.4 - Giới thiệu về biến toàn cục.**

Hiện tại, có hai điều bạn cần biết:
- Các định danh được khai báo bên trong phạm vi toàn cục có phạm vi từ điểm khai báo đến cuối tệp.
- Mặc dù các biến có thể được định nghĩa trong không gian tên toàn cục, nhưng điều này thường nên tránh (lý do được thảo luận trong bài học **7.8 - Tại sao biến toàn cục (không phải hằng) có hại**).

**Ví dụ:**
>```
>#include <iostream> // nhập khai báo của std::cout vào phạm vi toàn cục
>
>// Tất cả các câu lệnh sau đây đều là một phần của không gian tên toàn cục
>
>void foo();    // okay: tiền khai báo hàm
>int x;         // biên dịch được nhưng không khuyến khích: định nghĩa biến toàn cục không phải hằng (không có giá trị khởi tạo)
>int y { 5 };   // biên dịch được nhưng không khuyến khích: định nghĩa biến toàn cục không phải hằng (có giá trị khởi tạo)
>x = 5;         // lỗi biên dịch: các câu lệnh thực thi không được phép trong không gian tên
>
>int main()     // okay: định nghĩa hàm
>{
>    return 0;
>}
>
>void goo();    // okay: tiền khai báo hàm
>

### **Không gian tên `std`**



Khi C++ được thiết kế ban đầu, tất cả các định danh trong thư viện chuẩn C++ (bao gồm `std::cin` và `std::cout`) đều có sẵn để sử dụng mà không cần tiền tố `std::` (chúng là một phần của không gian tên toàn cục). Tuy nhiên, điều này có nghĩa là bất kỳ định danh nào trong thư viện chuẩn đều có thể xung đột với bất kỳ tên nào bạn chọn cho các định danh của riêng bạn (cũng được định nghĩa trong không gian tên toàn cục). Mã đang hoạt động đột nhiên có thể gặp phải xung đột đặt tên khi bạn `#include` một tệp mới từ thư viện chuẩn. Hoặc tệ hơn, các chương trình được biên dịch dưới một phiên bản C++ này có thể không được biên dịch dưới phiên bản C++ tương lai, vì các định danh mới được giới thiệu trong thư viện chuẩn có thể xung đột đặt tên với mã đã được viết. Vì vậy, C++ đã di chuyển tất cả các chức năng trong thư viện chuẩn vào một không gian tên được đặt tên là `std` (viết tắt của **"standard"**).

Hóa ra tên của `std::cout` thực sự không phải là `std::cout`. Nó thực sự chỉ là `cout`, và `std` là tên của không gian tên mà định danh `cout` là một phần. Bởi vì `cout` được định nghĩa trong không gian tên `std`, tên `cout` sẽ không xung đột với bất kỳ đối tượng hoặc hàm nào được đặt tên là `cout` mà chúng ta tạo bên ngoài không gian tên `std` (chẳng hạn như trong không gian tên toàn cục).

Khi truy cập một định danh được định nghĩa trong một không gian tên (ví dụ: `std::cout`), bạn cần thông báo cho trình biên dịch rằng chúng ta đang tìm kiếm một định danh được định nghĩa bên trong không gian tên (`std`).

>**Điểm mấu chốt**<br>
>Khi bạn sử dụng một định danh được định nghĩa bên trong một không gian tên (chẳng hạn như không gian tên std), bạn phải thông báo cho trình biên dịch rằng định danh đó nằm trong không gian tên.

Có một vài cách khác nhau để thực hiện việc này.

#### *Sử dụng tiền tố không gian tên `std::`*

Cách đơn giản nhất để báo cho trình biên dịch rằng chúng ta muốn sử dụng cout từ không gian tên `std` là sử dụng rõ ràng tiền tố `std::`. Ví dụ:

>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Hello world!"; // khi chúng ta nói cout, chúng ta muốn nói đến cout được định nghĩa trong không gian tên std
>    return 0;
>}
>```

Ký hiệu `::` là toán tử được gọi là toán tử phân giải phạm vi (scope resolution operator). Định danh ở bên trái của ký hiệu `::` xác định không gian tên mà tên ở bên phải của ký hiệu `::` nằm trong đó. Nếu không cung cấp định danh nào ở bên trái của ký hiệu `::`, thì không gian tên toàn cục được mặc định.

Vì vậy, khi chúng ta nói `std::cout`, chúng ta đang nói "`cout` được khai báo trong không gian tên `std`".

Đây là cách an toàn nhất để sử dụng `cout`, vì không có sự nhầm lẫn về việc `cout` nào chúng ta đang tham chiếu (cái nằm trong không gian tên `std`).

>**Thực hành tốt nhất**<br>
>Sử dụng tiền tố không gian tên tường minh để truy cập các định danh được định nghĩa trong một không gian tên.
Khi một định danh bao gồm tiền tố không gian tên, định danh đó được gọi là tên có định danh (qualified name).

### **Sử dụng using namespace std (và tại sao nên tránh)**

Một cách khác để truy cập các định danh bên trong một không gian tên là sử dụng **câu lệnh using-directive** (chỉ thị bằng từ khóa `using`). Đây là chương trình **`"Hello world"`** ban đầu của chúng tôi với một **using-directive**:



>```
>#include <iostream>
>
>using namespace std; // đây là một using-directive cho phép chúng ta truy cập các tên trong không gian tên std mà không cần tiền tố không gian tên
>
>int main()
>{
>    cout << "Hello world!";
>    return 0;
>}

**Using directive** cho phép chúng ta truy cập các tên trong một không gian tên mà không cần sử dụng tiền tố không gian tên. Vì vậy, trong ví dụ trên, khi trình biên dịch xác định định danh `cout` là gì, nó sẽ khớp với `std::cout`, mà do có **using-directive**, nên có thể truy cập được chỉ bằng `cout`.

Nhiều tài liệu, hướng dẫn và thậm chí cả một số IDE khuyên dùng hoặc sử dụng `using-directive` ở đầu chương trình. Tuy nhiên, sử dụng theo cách này là một thực hành xấu và rất không khuyến khích.

Xem xét chương trình sau:

>```
>#include <iostream> // imports the declaration of std::cout into the global scope
>
>using namespace std; // makes std::cout accessible as "cout"
>
>int cout() // defines our own "cout" function in the global namespace
>{
>    return 5;
>}
>
>int main()
>{
>    cout << "Hello, world!"; // Lỗi biên dịch! Chúng ta muốn sử dụng cout nào ở đây? Cái trong không gian tên std hay cái chúng ta đã định nghĩa ở trên?
>
>    return 0;
>}

Chương trình trên không được biên dịch vì bây giờ trình biên dịch không thể phân biệt được chúng ta muốn sử dụng hàm `cout` mà chúng ta đã định nghĩa hay `std::cout`.

Khi sử dụng **using-directive** theo cách này, bất kỳ định danh nào chúng ta định nghĩa đều có thể xung đột với bất kỳ định danh nào có tên giống hệt nhau trong không gian tên `std`. Thậm chí tệ hơn, trong khi tên định danh có thể không xung đột ngày nay, nó có thể xung đột với các định danh mới được thêm vào không gian tên `std` trong các bản sửa đổi ngôn ngữ tương lai. Đây chính là lý do tại sao tất cả các định danh trong thư viện chuẩn được chuyển vào không gian tên `std` ngay từ đầu!

>**Cảnh báo**<br>
>Tránh sử dụng **using-directives** (chẳng hạn như `using namespace std;`) ở đầu chương trình hoặc trong các tệp header. Chúng vi phạm lý do tại sao không gian tên được thêm vào ngay từ đầu.

>**Nội dung liên quan**<br>
>Chúng ta sẽ nói nhiều hơn về cách sử dụng using-declaration và using-directive (và cách sử dụng chúng một cách có trách nhiệm) trong bài **7.12 -- Using declaration và Using-directive**.

### **Cặp ngoặc nhọn (curly braces) và mã thụt lề**

Trong C++, **cặp ngoặc nhọn (curly braces)** thường được sử dụng để phân định một vùng phạm vi được lồng nhau bên trong một vùng phạm vi khác (cặp ngoặc nhọn cũng được sử dụng cho một số mục đích không liên quan đến phạm vi, chẳng hạn như **khởi tạo danh sách**). Ví dụ, một hàm được định nghĩa bên trong vùng phạm vi toàn cục sử dụng cặp ngoặc nhọn để tách vùng phạm vi của hàm ra khỏi phạm vi toàn cục.

Trong một số trường hợp nhất định, các định danh được định nghĩa bên ngoài cặp ngoặc nhọn vẫn có thể là một phần của phạm vi được xác định bởi cặp ngoặc nhọn thay vì phạm vi xung quanh - tham số hàm là một ví dụ điển hình.

**Ví dụ:**
>```
>#include <iostream> // imports the declaration of std::cout into the global scope
>
>void foo(int x) // foo được định nghĩa trong phạm vi toàn cục, x được định nghĩa trong phạm vi của foo()
>{ // Khối nhọn được sử dụng để phân định vùng phạm vi lồng nhau cho hàm foo()
>    std::cout << x << '\n';
>} // x hết hiệu lực ở đây
>
>int main()
>{ // Khối nhọn được sử dụng để phân định vùng phạm vi lồng nhau cho hàm main()
>    foo(5);
>
>    int x { 6 }; // x được định nghĩa trong phạm vi của main()
>    std::cout << x << '\n';
>
>    return 0;
>} // x hết hiệu lực ở đây
>// foo và main (và std::cout) hết hiệu lực ở đây (cuối tệp)

Theo quy ước, mã tồn tại bên trong một vùng phạm vi lồng nhau được thụt lề vào một cấp, cả để dễ đọc và để giúp chỉ ra rằng nó tồn tại bên trong một vùng phạm vi riêng biệt.

Các lệnh `#include` và định nghĩa hàm cho `foo()` và `main()` tồn tại trong vùng phạm vi toàn cục, vì vậy chúng không cần phải thụt lề. Các câu lệnh bên trong mỗi hàm tồn tại bên trong vùng phạm vi lồng nhau của hàm, vì vậy chúng được thụt lề một cấp.
