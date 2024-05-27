## **Bài 4.6: <u>Số nguyên kích thước cố định và `size_t`</u>** 

Trong các bài học trước về số nguyên, chúng ta đã đề cập rằng C++ chỉ đảm bảo các biến kiểu nguyên có kích thước tối thiểu - nhưng chúng có thể lớn hơn, tùy thuộc vào hệ thống đích.

### **Tại sao kích thước của số nguyên lại không cố định?**

Lý do chính cho điều này bắt nguồn từ những ngày đầu của C, khi máy tính còn chậm và hiệu suất là mối quan tâm hàng đầu. C cố tình để kích thước của một số nguyên là tùy ý để trình biên dịch có thể chọn kích thước cho int sao cho hoạt động tốt nhất trên kiến trúc máy tính cụ thể.

### **Vấn đề của số nguyên kích thước không cố định**

Theo tiêu chuẩn hiện đại, việc sử dụng số nguyên có kích thước không cố định có thể dẫn đến một số vấn đề:
- **Khó dự đoán hành vi chương trình:** Do kích thước của `int` có thể thay đổi, việc dự đoán cách các biến `int` sẽ được lưu trữ và xử lý trên các hệ thống khác nhau trở nên khó khăn. Điều này có thể dẫn đến lỗi chương trình và hành vi không mong muốn.
- **Hạn chế phạm vi giá trị:** Kích thước nhỏ hơn của `int` trên một số hệ thống có thể hạn chế phạm vi giá trị mà chúng có thể lưu trữ. Điều này có thể gây ra vấn đề nếu chương trình cần xử lý các giá trị lớn.
- **Lãng phí bộ nhớ:** Trên các hệ thống có `int` lớn hơn, việc sử dụng `int` nhỏ hơn có thể dẫn đến lãng phí bộ nhớ.

>**Ngoài lề**<br>
>Trong hầu hết các trường hợp, chúng ta chỉ tạo một số lượng nhỏ biến `int` tại một thời điểm và chúng thường bị hủy tại cuối hàm nơi chúng được tạo. Trong những trường hợp như vậy, việc lãng phí *2 byte* bộ nhớ cho mỗi biến không phải là vấn đề (phạm vi bị hạn chế là vấn đề lớn hơn). Tuy nhiên, trong trường hợp chương trình của chúng ta phân bổ hàng nghìn hoặc hàng triệu biến `int`, việc lãng phí *2 byte* bộ nhớ cho mỗi biến có thể ảnh hưởng đáng kể đến tổng thể dung lượng bộ nhớ sử dụng của chương trình.

### **Số nguyên kích thước cố định**

Để giải quyết các vấn đề nêu trên, **C99** đã định nghĩa một tập hợp các số nguyên kích thước cố định (trong tiêu đề `stdint.h`) được đảm bảo có cùng kích thước trên mọi kiến trúc.

Các kiểu dữ liệu này được định nghĩa như sau:

| Tên           | Kiểu   | Phạm vi                                                  | Ghi chú                                                                        |
|-----------------|--------|----------------------------------------------------------|--------------------------------------------------------------------------------|
| `std::int8_t`   | 1 byte | -128 đến 127                                             | Thường được coi như một signed char trên nhiều hệ thống. Xem lưu ý bên dưới.   |
| `std::uint8_t`  | 1 byte | 0 đến 255                                                | Thường được coi như một unsigned char trên nhiều hệ thống. Xem lưu ý bên dưới. |
| `std::int16_t`  | 2 byte | -32,768 đến 32,767                                       |                                                                                |
| `std::uint16_t` | 2 byte | 0 đến 65,535                                             |                                                                                |
| `std::int32_t`  | 4 byte | -2,147,483,648 đến 2,147,483,647                         |                                                                                |
| `std::uint32_t` | 4 byte | 0 đến 4,294,967,295                                      |                                                                                |
| `std::int64_t`  | 8 byte | -9,223,372,036,854,775,808 đến 9,223,372,036,854,775,807 |                                                                                |
| `std::uint64_t` | 8 byte | 0 đến 18,446,744,073,709,551,615                         |                                                                                |

C++ chính thức áp dụng các số nguyên kích thước cố định này như một phần của **C++11**. Bạn có thể truy cập chúng bằng cách bao gồm tiêu đề `<cstdint>`, nơi chúng được định nghĩa bên trong không gian tên `std`. Đây là một ví dụ:

>```
>#include <cstdint> // for fixed-width integers
>#include <iostream>
>
>int main()
>{
>    std::int16_t i{5};
>    std::cout << i << '\n';
>    return 0;
>}
>```

### **Nhược điểm của số nguyên kích thước cố định**

Thông thường, có hai nhược điểm thường được nêu ra về số nguyên kích thước cố định.

Thứ nhất, số nguyên kích thước cố định không được đảm bảo được định nghĩa trên tất cả các kiến trúc. Chúng chỉ tồn tại trên các hệ thống có các kiểu dữ liệu cơ bản khớp với chiều rộng của chúng và tuân theo biểu diễn nhị phân nhất định. Chương trình của bạn sẽ không thể biên dịch trên bất kỳ kiến trúc nào không hỗ trợ một số nguyên kích thước cố định mà chương trình của bạn đang sử dụng. Tuy nhiên, do hầu hết các kiến trúc hiện đại đều được chuẩn hóa xung quanh các biến 8/16/32/64-bit, nên điều này không có khả năng là vấn đề trừ khi chương trình của bạn cần có tính di động trên một số kiến trúc mainframe hoặc kiến trúc nhúng độc lạ.

Thứ hai, nếu bạn sử dụng một số nguyên kích thước cố định, nó có thể chậm hơn một kiểu rộng hơn trên một số kiến trúc. Ví dụ, nếu bạn cần một số nguyên được đảm bảo là 32 bit, bạn có thể quyết định sử dụng `std::int32_t`, nhưng CPU của bạn thực sự có thể xử lý các số nguyên 64 bit nhanh hơn. Tuy nhiên, chỉ vì CPU của bạn có thể xử lý một kiểu nhất định nhanh hơn không có nghĩa là chương trình của bạn sẽ nhanh hơn tổng thể - các chương trình hiện đại thường bị hạn chế bởi sử dụng bộ nhớ hơn là CPU, và dung lượng bộ nhớ lớn hơn có thể làm chậm chương trình của bạn nhiều hơn so với việc xử lý CPU nhanh hơn. Rất khó để biết chắc chắn mà không thực sự đo lường.

### **Số nguyên nhanh và nhỏ nhất**

Để giúp giải quyết những nhược điểm nêu trên, C++ cũng định nghĩa hai tập hợp số nguyên thay thế được đảm bảo được định nghĩa.

**Các kiểu nhanh** (*`std::int_fast#_t`* và *`std::uint_fast#_t`*): Cung cấp kiểu số nguyên có dấu/không dấu nhanh nhất với chiều rộng tối thiểu *#* bit (trong đó *#* = 8, 16, 32 hoặc 64). Ví dụ, `std::int_fast32_t` sẽ cung cấp cho bạn kiểu số nguyên có dấu nhanh nhất có ít nhất 32 bit. "Nhanh nhất" ở đây có nghĩa là kiểu số nguyên có thể được CPU xử lý nhanh nhất.

**Các kiểu nhỏ nhất** (*`std::int_least#_t`* và *`std::uint_least#_t`*): Cung cấp kiểu số nguyên có dấu/không dấu nhỏ nhất với chiều rộng tối thiểu *#* bit (trong đó *#* = 8, 16, 32 hoặc 64). Ví dụ, `std::uint_least32_t` sẽ cung cấp cho bạn kiểu số nguyên không dấu nhỏ nhất có ít nhất 32 bit.

**Đây là một ví dụ từ Visual Studio của tác giả (console 32-bit):**
>```
>#include <cstdint> // for fast and least types
>#include <iostream>
>
>int main()
>{
>    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
>    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
>    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
>    std::cout << '\n';
>    std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
>    std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
>    std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
>    
>    return 0;
>}
>```

Đoạn code này cho kết quả:
>```
>least 8:  8 bits
>least 16: 16 bits
>least 32: 32 bits
>
>fast 8:  8 bits
>fast 16: 32 bits
>fast 32: 32 bits
>```

Bạn có thể thấy rằng `std::int_least16_t` là 16 bit, trong khi `std::int_fast16_t` thực sự là 32 bit. Điều này là do trên máy của tác giả, các số nguyên 32 bit được xử lý nhanh hơn các số nguyên 16 bit.

Tuy nhiên, các số nguyên nhanh và nhỏ nhất này cũng có những nhược điểm riêng:

Thứ nhất, không nhiều lập trình viên thực sự sử dụng chúng và việc không quen thuộc có thể dẫn đến lỗi.
Thứ hai, các kiểu nhanh có thể dẫn đến lãng phí bộ nhớ, vì kích thước thực tế của chúng có thể lớn hơn so với tên gọi của chúng. Nghiêm trọng hơn, vì kích thước của các số nguyên nhanh/nhỏ nhất có thể thay đổi, nên chương trình của bạn có thể thể hiện các hành vi khác nhau trên các kiến trúc nơi chúng có kích thước khác nhau. Ví dụ:

>```
>#include <cstdint>
>#include <iostream>
>
>int main()
>{
>    std::uint_fast16_t sometype { 0 };
>    sometype = sometype - 1; // cố tình tràn số để kích hoạt hành vi "cuộn tròn"
>
>    std::cout << sometype << '\n';
>
>    return 0;
>}
>```

Đoạn code này sẽ tạo ra các kết quả khác nhau tùy thuộc vào việc `std::uint_fast16_t` là 16, 32 hoặc 64 bit.

Rất khó để biết chương trình của bạn có thể không hoạt động như mong đợi ở đâu cho đến khi bạn kiểm tra nghiêm ngặt chương trình của mình trên các kiến trúc như vậy.

### **`std::int8_t` và `std::uint8_t` có thể hoạt động giống như `char`**

Do sự thiếu sót trong đặc tả C++, hầu hết các trình biên dịch định nghĩa và xử lý `std::int8_t` và `std::uint8_t` (và các kiểu tương ứng nhanh và nhỏ nhất) giống hệt với các kiểu `signed char` và `unsigned char` tương ứng. Điều này có nghĩa là các kiểu 8-bit này có thể (hoặc có thể không) hoạt động khác so với các kiểu kích thước cố định còn lại, điều này có thể dẫn đến lỗi. Hành vi này phụ thuộc vào hệ thống, vì vậy một chương trình hoạt động chính xác trên một kiến trúc có thể không biên dịch hoặc hoạt động chính xác trên một kiến trúc khác.

Chúng tôi sẽ hiển thị một ví dụ về điều này trong bài học 4.12 - Giới thiệu về chuyển đổi kiểu và static_cast.

Khi lưu trữ các giá trị số nguyên mà kích thước cụ thể là quan trọng, thường tốt nhất là tránh `std::int8_t` và `std::uint8_t` (và các kiểu nhanh và nhỏ nhất liên quan) và sử dụng `std::int16_t` hoặc `std::uint16_t` thay thế.

>**Cảnh báo**<br>
>Các kiểu số nguyên kích thước cố định 8-bit thường được xử lý giống như các ký tự `char` thay vì các giá trị số nguyên (và điều này có thể thay đổi theo từng hệ thống). Ưu tiên các kiểu số nguyên cố định 16-bit cho hầu hết các trường hợp.

### **Các thực hành tốt nhất cho kiểu số nguyên**

Mặc dù C++ cung cấp nhiều lựa chọn để biểu diễn các giá trị số nguyên, không có giải pháp ***"phù hợp cho tất cả"***. Dưới đây là một số hướng dẫn giúp bạn chọn loại phù hợp nhất cho tình huống của mình:

- **Ưu tiên tính chính xác hơn tốc độ:** Mục tiêu là tạo ra mã hoạt động đáng tin cậy thay vì chỉ tập trung đạt được tốc độ thực thi nhanh nhất. Lỗi thời gian biên dịch dễ sửa hơn lỗi thời gian chạy.

- **Kiểu kích thước cố định để đảm bảo kích thước:** Nếu chương trình của bạn phụ thuộc vào các số nguyên có kích thước cụ thể, hãy sử dụng các kiểu `std::int#_t` (với # là 8, 16, 32 hoặc 64) thay vì các kiểu `fast` hoặc `least`. Bạn luôn có thể điều chỉnh mã sau này nếu cần hỗ trợ nền tảng không biên dịch được với một kiểu kích thước cố định cụ thể.

- **Sử dụng `int` cho mục đích chung:** Khi kích thước của số nguyên không quan trọng và biến chỉ tồn tại tạm thời (như bộ đếm vòng lặp), `int` là một lựa chọn tốt. Nó có khả năng hiệu quả cho hầu hết các trường hợp sử dụng phổ biến như nhập liệu người dùng hoặc đếm cơ bản.

- **`std::int#_t` cho các khoảng cụ thể:** Nếu bạn cần lưu trữ giá trị trong một khoảng được đảm bảo, hãy chọn loại `std::int#_t` phù hợp dựa trên các giá trị dự kiến.

- **`std::uint#_t` cho thao tác bit:** Khi làm việc với các phép toán bit hoặc yêu cầu hành vi tràn số được xác định rõ ràng, hãy sử dụng các kiểu `std::uint#_t`.

**Tránh các kiểu này khi có thể:**
- `short` và `long`: Chọn các kiểu kích thước cố định để có hành vi dự đoán được.
- Kiểu không dấu cho số lượng: Sử dụng kiểu có dấu cho các giá trị biểu thị số lượng có thể âm.
- Kiểu số nguyên kích thước cố định 8-bit: Hành vi của chúng có thể không nhất quán trên các hệ thống.
- Kiểu kích thước cố định nhanh/nhỏ nhất: Kích thước của chúng có thể thay đổi, gây ra các vấn đề tiềm ẩn trên các kiến trúc khác nhau.
- Kiểu phụ thuộc vào trình biên dịch: Sử dụng các kiểu chuẩn để đảm bảo khả năng di động tốt hơn.

Lưu ý, đây chỉ là những khuyến nghị chung. Lựa chọn tốt nhất cho chương trình của bạn sẽ phụ thuộc vào các nhu cầu cụ thể và nền tảng mục tiêu của nó.

### **Kiểu `std::size_t`là gì?**

**Hãy xem xét đoạn mã sau:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << sizeof(int) << '\n';
>
>    return 0;
>}
>```

Trên máy tính của tác giả, đoạn mã này in ra:
>`4`

Rất đơn giản, phải không? Chúng ta có thể suy luận rằng toán tử `sizeof` trả về một giá trị số nguyên - nhưng kiểu số nguyên đó là gì? Một `int`? Một `short`? Câu trả lời là `sizeof` trả về một giá trị thuộc kiểu `std::size_t`. `std::size_t` được định nghĩa là một kiểu số nguyên không dấu được triển khai theo cách phụ thuộc vào hệ thống.

>**Lưu ý quan trọng**<br>
>`std::size_t` thường được sử dụng để biểu diễn kích thước hoặc độ dài của các đối tượng, đặc biệt là trong thư viện chuẩn C++.

Điều thú vị là, chúng ta có thể sử dụng toán tử `sizeof` (trả về một giá trị kiểu `std::size_t`) để truy vấn kích thước của chính `std::size_t`:
>```
>#include <cstddef> // for std::size_t
>#include <iostream>
>
>int main()
>{
>    std::cout << sizeof(std::size_t) << '\n';
>
>    return 0;
>}
>```

Khi được biên dịch thành ứng dụng console 32-bit (4 byte) trên hệ thống của tác giả, đoạn mã này in ra:
>`4`

`std::size_t` được định nghĩa trong một số header khác nhau. `<cstddef>` là lựa chọn tốt nhất để include, vì nó chứa ít định danh được xác định khác nhất.

>**Thực hành tốt nhất**<br>
>Nếu bạn sử dụng `std::size_t` trực tiếp trong code, hãy include một trong những header định nghĩa `std::size_t` (khuyến nghị `<cstddef>`).
>
>Sử dụng `sizeof` không yêu cầu header (mặc dù nó trả về một giá trị có kiểu là `std::size_t`).

**Kích thước của `std::size_t`**

Giống như kiểu số nguyên có thể thay đổi kích thước tùy theo hệ thống, `std::size_t` cũng có kích thước khác nhau. `std::size_t` được đảm bảo là không dấu và có kích thước tối thiểu là 16 bit, nhưng trên hầu hết các hệ thống, nó sẽ tương đương với độ rộng địa chỉ của ứng dụng. Nghĩa là, đối với các ứng dụng 32-bit, `std::size_t` thường là một số nguyên không dấu 32-bit, và đối với ứng dụng 64-bit, `std::size_t` thường là một số nguyên không dấu 64-bit.




### **`std::size_t` áp đặt một giới hạn trên về kích thước của một đối tượng được tạo trên hệ thống. <sub>(Bài đọc thêm)</sup>**

Toán tử `sizeof` phải có khả năng trả về kích thước byte của một đối tượng dưới dạng giá trị kiểu `std::size_t`. Do đó, kích thước byte của một đối tượng không được lớn hơn giá trị lớn nhất mà `std::size_t` có thể chứa. Nếu có thể tạo một đối tượng lớn hơn, `sizeof` sẽ không thể trả về kích thước byte của nó, vì nó sẽ nằm ngoài phạm vi mà `std::size_t` có thể lưu trữ.

Do đó, bất kỳ đối tượng nào có kích thước (tính bằng byte) lớn hơn giá trị lớn nhất mà một đối tượng kiểu `std::size_t` có thể chứa đều được coi là không hợp lệ (và sẽ gây ra lỗi biên dịch).

Ví dụ, hãy giả sử rằng `std::size_t` có kích thước 4 byte trên hệ thống của chúng ta. Một kiểu số nguyên không dấu 4 byte có phạm vi từ `0` đến `4.294.967.295`. Do đó, một đối tượng `std::size_t` 4 byte có thể chứa bất kỳ giá trị nào từ `0` đến `4.294.967.295`. Nếu kích thước byte của một đối tượng lớn hơn 4.294.967.295 byte, thì `sizeof` sẽ không thể trả về kích thước của đối tượng đó một cách chính xác, vì giá trị sẽ nằm ngoài phạm vi của `std::size_t`. Do đó, không thể tạo đối tượng kích thước lớn hơn 4.294.967.295 byte.

Vào thời các ứng dụng 8 bit và 16 bit là tiêu chuẩn, điều này đặt ra một hạn chế đáng kể về kích thước của các đối tượng. Trong kỷ nguyên 32 bit và 64 bit, điều này hiếm khi xảy ra và do đó không phải là điều bạn thường cần phải lo lắng.


>**Ngoài lề**<br>
>Kích thước của `std::size_t` áp đặt một giới hạn trên lý thuyết nghiêm ngặt cho kích thước của một đối tượng. Trong thực tế, đối tượng lớn nhất có thể tạo ra có thể nhỏ hơn giá trị này (có thể là đáng kể).
>
>Một số trình biên dịch giới hạn đối tượng lớn nhất có thể tạo ra bằng một nửa giá trị tối đa của `std::size_t` (có thể tìm thấy giải thích cho điều này [ở đây](https://stackoverflow.com/a/42428240)).
>
>Các yếu tố khác cũng có thể đóng vai trò, chẳng hạn như dung lượng bộ nhớ *contiguous* (liền kề) có sẵn trên máy tính của bạn để phân bổ.

