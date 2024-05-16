## **Bài 1.5: <u>Giới thiệu về `iostream`: `cout`, `cin` và `endl`</u>**


Trong bài học này, chúng ta sẽ tìm hiểu thêm về `std::cout`, đối tượng đã được sử dụng trong chương trình **"Hello world!"** để xuất văn bản **"Hello world!"** ra màn hình console. Chúng ta cũng sẽ khám phá cách lấy dữ liệu nhập từ người dùng, giúp c chương trình trở nên tương tác hơn.

### **Thư viện vào/ra:**

- Thư viện vào/ra (io library) là một phần của thư viện chuẩn C++ dùng để xử lý các tác vụ nhập và xuất cơ bản.
- Chúng ta sẽ sử dụng các chức năng trong thư viện này để lấy dữ liệu từ bàn phím và xuất dữ liệu ra màn hình console.
- Phần "io" trong "`iostream`" là viết tắt của "`input/output`" (vào/ra).

Để sử dụng các chức năng được định nghĩa trong thư viện `iostream`, chúng ta cần thêm header `iostream` vào đầu của bất kỳ tệp code nào sử dụng các nội dung được định nghĩa trong `iostream`, như sau:
>`#include <iostream>`\
>`// Phần còn lại của code sử dụng các chức năng của iostream ở đây `

### `std::cout`


Thư viện `iostream` chứa một số biến được định sẵn để chúng ta sử dụng. Một trong những biến hữu ích nhất là `std::cout`, cho phép chúng ta gửi dữ liệu đến console để in ra dưới dạng văn bản. `cout` là viết tắt của "character output" (xuất ký tự).

Ví dụ chương trình `Hello World`:

>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    std::cout << "Hello world!"; // In ra "Hello world!" ra màn hình console
>
>    return 0;
>}
>```

Trong chương trình này, chúng ta đã bao gồm `iostream` để có thể truy cập `std::cout`. Bên trong hàm `main`, chúng ta sử dụng `std::cout` cùng với toán tử chèn (`<<`) để gửi văn bản `"Hello world!"` đến console để in ra.

`std::cout` có thể in nhiều thứ:
- std::cout không chỉ in được text, mà còn có thể in cả số:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    std::cout << 4; // In số 4 ra màn hình console
>
>    return 0;
>}
>```

    Kết quả sẽ là:
> `4`

- `std::cout` cũng có thể được dùng để in giá trị của các biến:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    int x { 5 }; // Khai báo biến x kiểu int và khởi tạo giá trị 5
>    std::cout << x; // In giá trị của x (5) ra màn hình console
>
>    return 0;
>}
>```
- Để in nhiều thứ trên cùng một dòng, toán tử chèn (`<<`) có thể được sử dụng nhiều lần trong một câu lệnh duy nhất để nối (liên kết) nhiều đoạn xuất ra thành một chuỗi.
- Ví dụ:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    std::cout << "Hello" << " world!";
>    return 0;
>}
>```

    Chương trình này sẽ in ra:
> `Hello world!`
- Ví dụ in cả text và giá trị biến:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    int x { 5 };
>    std::cout << "x is equal to: " << x;
>    return 0;
>}
>```

    Chương trình này sẽ in ra:
>`x is equal to: 5`

<u>Lưu ý về tiền tố `std::`</u>

Giải thích về tiền tố `std::` sẽ được đề cập trong bài học **2.9 - Xung đột tên và Giới thiệu về Namespaces.**

### `std::endl`

- Bạn có thể nghĩ chương trình này sẽ in ra gì?
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout
>
>int main()
>{
>    std::cout << "Hi!";
>    std::cout << "My name is Alex.";
>    return 0;
>}
>```

    Kết quả có thể khiến bạn bất ngờ:
    >`Hi!My name is Alex.`

- Các câu lệnh in riêng biệt (`std::cout`) không nhất thiết dẫn đến in ra các dòng riêng biệt trên console.
- **In xuống dòng chủ động:**
    - Nếu muốn in ra các dòng riêng biệt trên console, chúng ta cần thông báo cho console biết khi nào di chuyển con trỏ xuống dòng.
    - Một cách để thực hiện điều đó là sử dụng `std::endl`. Khi được xuất ra với `std::cout`, `std::endl` sẽ in một ký tự xuống dòng (`\n`) vào console (khiến con trỏ nhảy đến đầu dòng tiếp theo). Trong ngữ cảnh này, `endl` là viết tắt của "end line" (kết thúc dòng).
- Ví dụ:
>```
>#include <iostream> // Bao gồm header iostream để sử dụng std::cout và std::endl
>
>int main()
>{
>    std::cout << "Hi!" << std::endl; // std::endl sẽ khiến con trỏ nhảy xuống dòng tiếp theo
>    std::cout << "My name is Alex." << std::endl;
>
>    return 0;
>}
>```

    Chương trình này sẽ in ra:
    >`Hi!`\
    >`My name is Alex.`

>**Mẹo:**
>Mẹo về `std::endl`:
>
>Trong chương trình trên, `std::endl` thứ hai về mặt kỹ thuật không cần thiết, vì chương trình kết thúc ngay sau đó. Tuy nhiên, nó có một vài mục đích hữu ích.
>
>Thứ nhất, nó giúp chỉ ra rằng dòng xuất ra là một "hoàn chỉnh" (chứ không phải là đầu ra một phần được hoàn thành ở đâu đó sau trong code). Theo nghĩa này, nó hoạt động tương tự như việc sử dụng dấu chấm trong tiếng Anh.
>
>Thứ hai, nó đặt con trỏ trên dòng tiếp theo, vì vậy nếu sau này chúng ta thêm các dòng xuất ra bổ sung (ví dụ: yêu cầu chương trình nói "bye!"), các dòng đó sẽ xuất hiện ở vị trí mong đợi (chứ không phải được nối vào dòng xuất ra trước đó).
>
>Thứ ba, sau khi chạy một file thực thi từ dòng lệnh, một số hệ điều hành không xuất ra dòng mới trước khi hiển thị lại dấu nhắc lệnh. Nếu chương trình của chúng ta không kết thúc với con trỏ trên một dòng mới, dấu nhắc lệnh có thể xuất hiện được nối vào dòng xuất ra trước đó, thay vì ở đầu dòng mới như người dùng mong đợi.
>



### **`std::cout` được đệm (buffered)**

Hãy tưởng tượng về một tàu lượn siêu tốc ở công viên giải trí yêu thích của bạn. Khách tham quan đến (với tốc độ thay đổi) và xếp hàng. Theo định kỳ, một toa tàu đến và chở khách (tối đa bằng sức chứa của toa tàu). Khi toa tàu đầy hoặc đủ thời gian đã trôi qua, toa tàu khởi hành với một nhóm hành khách và bắt đầu chuyến đi. Bất kỳ hành khách nào không thể lên toa tàu hiện tại sẽ đợi toa tàu tiếp theo.

Cách thức hoạt động này tương tự như cách dữ liệu xuất ra được gửi đến `std::cout` thường được xử lý trong C++. Các câu lệnh trong chương trình của chúng ta yêu cầu gửi dữ liệu xuất ra cho console. Tuy nhiên, dữ liệu xuất ra đó thường không được gửi ngay lập tức tới console. Thay vào đó, dữ liệu xuất ra được yêu cầu sẽ "xếp hàng" và được lưu trữ trong một vùng nhớ được dành riêng để thu thập các yêu cầu như vậy (gọi là **bộ đệm** - **buffer**). Định kỳ, bộ đệm sẽ được "xả" (`flush`), nghĩa là tất cả dữ liệu được thu thập trong bộ đệm được chuyển đến đích của nó (trong trường hợp này là console).



> **Chú thích của tác giả:**\
> Theo một phép ẩn dụ khác, việc xả bộ đệm giống như xả nước bồn cầu. Tất cả "dữ liệu xuất ra" được thu thập của bạn sẽ được chuyển đến bất cứ nơi nào nó sẽ đến tiếp theo. (Không hay cho lắm!)

Điều này cũng có nghĩa là nếu chương trình của bạn bị lỗi, dừng đột ngột (abort) hoặc tạm dừng (ví dụ: để gỡ lỗi) trước khi bộ đệm được xả, bất kỳ dữ liệu xuất ra nào vẫn còn chờ trong bộ đệm sẽ không được hiển thị.



> **Lưu ý quan trọng:**
>
>Trái ngược với xuất ra được đệm là xuất ra không được đệm (unbuffered output). Với xuất ra không được đệm, mỗi yêu cầu xuất ra riêng lẻ sẽ được gửi trực tiếp đến thiết bị đầu ra.
>
>Viết dữ liệu vào bộ đệm thường nhanh, trong khi truyền một loạt dữ liệu đến thiết bị đầu ra thì tương đối chậm. Việc đệm có thể cải thiện hiệu suất đáng kể bằng cách giảm thiểu số lượng truyền chậm cần thực hiện khi có nhiều yêu cầu xuất ra.

### **`std::endl` vs ‘`\n`’**



Trong C++, `std::endl` và '`\n`' đều được sử dụng để in xuống dòng, nhưng chúng có sự khác biệt về mặt hiệu quả:
- `std::endl`:
    - Thực hiện hai tác vụ:
        - Di chuyển con trỏ xuống dòng tiếp theo trên console.
        - Xả (flush) bộ đệm của `std::cout`. Bộ đệm là một vùng nhớ tạm thời lưu trữ dữ liệu xuất ra trước khi gửi đến console.
    - Xả bộ đệm có thể hơi kém hiệu quả vì nó liên quan đến việc ghi dữ liệu ra thiết bị đầu ra ngay cả khi chưa cần thiết.
- '`\n`'
    - Chỉ thực hiện một tác vụ: di chuyển con trỏ xuống dòng tiếp theo.
    - Không xả bộ đệm. Hệ thống sẽ tự động xả bộ đệm theo định kỳ, thường là một cách hiệu quả hơn.
    - Thường được ưu tiên sử dụng hơn vì nó:
        - Hiệu quả hơn: Tránh việc xả bộ đệm không cần thiết.
        - Gọn nhẹ hơn: Dễ gõ hơn `std::endl`.
        - Linh hoạt hơn: Có thể nhúng vào trong chuỗi ký tự.
    - Ví dụ:
    >```
    >#include <iostream> // for std::cout
    >
    >int main()
    >{
    >    int x { 5 };
    >    std::cout << "x is equal to: " << x << '\n'; // Sử dụng '\n' đơn lẻ
    >    std::cout << "And that's all, folks!\n"; // Nhúng '\n' vào chuỗi ký tự (dùng dấu ngoặc kép đôi, không dùng đơn)
    >    return 0;
    >}
    >```

    - Kết quả:
    >`x is equal to: 5`\
    >`And that's all, folks!`
  - Lưu ý về cách sử dụng ký tự xuống dòng ('`\n`')
    - Khi sử dụng một mình để xuống dòng, '`\n`' cần được đặt trong dấu ngoặc đơn.
    - Khi nhúng vào chuỗi ký tự được bao bọc bởi dấu ngoặc kép đôi, không cần thêm dấu ngoặc đơn cho '`\n`'.

>**Thực hành tốt nhất:**\
>Sử dụng '`\n`' thay vì `std::endl` khi in ra văn bản trên console để cải thiện hiệu suất.

>**Cảnh báo:**
> - '`\n`' sử dụng dấu gạch chéo ngược (`\`) để biểu thị ký tự đặc biệt (giống như tất cả các ký tự đặc biệt trong C++), không phải là dấu gạch chéo xuôi (`/`).
> - Sử dụng dấu g/ạch chéo xuôi (`/n`) hoặc bao gồm các ký tự khác bên trong dấu ngoặc đơn (ví dụ: '` \n`' hoặc '`.\n') sẽ dẫn đến kết quả không mong đợi.

### `std::cin`

- `std::cin` là một biến được định sẵn khác trong thư viện `iostream`.
- Trong khi `std::cout` in dữ liệu ra console sử dụng toán tử chèn (`<<`), thì `std::cin` (viết tắt của "character input" - nhập ký tự) đọc dữ liệu nhập từ bàn phím bằng toán tử trích xuất (`>>`).
- Dữ liệu nhập phải được lưu trữ trong một biến để sử dụng.
- Ví dụ:
>```
>#include <iostream>
>
>int main () {
>	int x;   // định nghĩa biến x để chứa đầu vào của người dùng (và khởi tạo giá trị cho nó)
>	std::cout << "Enter a number: ";	// yêu cầu người dùng nhập số
>	std::cin >> x;                      // lấy số từ bàn phím và lưu trữ trong biến x
>	std::cout << "You entered " << x << '\n';
>	return 0;
>}
>```

Hãy thử biên dịch và chạy chương trình này. Khi bạn chạy chương trình, dòng `5` sẽ in ra "`Enter a number: `". Khi mã đến dòng `8`, chương trình sẽ chờ bạn nhập dữ liệu. Sau khi bạn nhập một số (và nhấn `enter`), số bạn nhập sẽ được gán cho biến `x`. Cuối cùng, trên dòng `10`, chương trình sẽ in ra "`You entered `" theo sau là số bạn vừa nhập.

Ví dụ (tôi nhập 4):
>`Enter a number: 4`\
>`You entered 4`
 
Đây là một cách đơn giản để lấy dữ liệu nhập từ bàn phím của người dùng và chúng ta sẽ sử dụng nó trong nhiều ví dụ sắp tới. Lưu ý rằng bạn không cần sử dụng '`\n`' khi chấp nhận đầu vào, vì người dùng sẽ cần nhấn phím `enter` để đầu vào của họ được chấp nhận và điều này sẽ di chuyển con trỏ xuống dòng tiếp theo trên console.

**Đọc nhiều số trên một dòng:**
- Trong C++, bạn có thể sử dụng toán tử trích xuất (`>>`) để đọc nhiều giá trị được phân cách bởi khoảng trắng (thường là dấu cách hoặc tab) từ đầu vào tiêu chuẩn (`std::cin`) và lưu trữ chúng vào các biến khác nhau.
- Dưới đây là một ví dụ được cải tiến kết hợp các phương pháp hay nhất:

>```
>#include <iostream>  // for std::cout and std::cin
>
>int main()
>{
>    std::cout << "Enter two numbers seperated by a space: ";
>
>    int x, y;       // define variable x and y to hold user input
>    std::cin >> x >> y; // get number from keyboard and store it in variable x
>
>    std::cout << "You entered " << x << " and " << y << '\n';
>    return 0;
>}
>```

- Chương trình sẽ in ra:
>`Enter two numbers seperated by a space:  5 6`\
>`You entered 5 and 6`

>**Thực tiễn**\
>Mặc dù giá trị do người dùng cung cấp từ `std::cin` cuối cùng sẽ ghi đè lên giá trị khởi tạo, nhưng có một số lý do chính đáng để khởi tạo biến trước khi sử dụng chúng với `std::cin`:
> - **Rõ ràng và minh bạch**: Khởi tạo làm cho code của bạn dễ đọc hơn và thể hiện rõ ràng về kiểu dữ liệu dự định và giá trị mặc định tiềm năng của biến. Nó làm rõ rằng biến không được sử dụng trong trạng thái chưa được khởi tạo, điều này có thể dẫn đến hành vi không mong đợi.
> - **Xử lý lỗi**: Nếu `std::cin` gặp phải đầu vào không hợp lệ không thể chuyển đổi thành kiểu biến mong đợi (ví dụ: nhập chuỗi trong khi cần số nguyên), trạng thái của biến sẽ `become undefined` (trở nên không xác định). Tuy nhiên, nếu biến được khởi tạo trước, bạn có thể có một giá trị mặc định đã biết để làm việc, `potentially aiding in error handling` (có khả năng hỗ trợ trong việc xử lý lỗi).
> - **Tính nhất quán**: Thực thi việc khởi tạo như một practice (thực hành) chung thúc đẩy phong cách code nhất quán và giảm thiểu rủi ro gây ra lỗi do vô tình sử dụng các biến chưa được khởi tạo ở các phần khác của code.






