## **Bài 4.3: <u>Kích thước đối tượng và toán tử `sizeof`</u>** 

Như bạn đã học trong bài học [**4.1 - Giới thiệu về kiểu dữ liệu cơ bản**](lesson4_1.ipynb), bộ nhớ trên các máy tính hiện đại thường được tổ chức thành các đơn vị **byte**, mỗi **byte** có một địa chỉ duy nhất. Cho đến thời điểm này, việc coi bộ nhớ như một dãy các ngăn tủ hoặc hộp thư nơi chúng ta có thể lưu trữ và truy xuất thông tin, và biến là tên để truy cập vào các ngăn tủ hoặc hộp thư đó, là một cách hữu ích.



Tuy nhiên, phép so sánh này không hoàn toàn chính xác ở một khía cạnh - hầu hết các đối tượng thực sự chiếm hơn 1 byte bộ nhớ. Một đối tượng đơn có thể sử dụng 1, 2, 4, 8 hoặc thậm chí nhiều địa chỉ bộ nhớ liên tiếp hơn. Lượng bộ nhớ mà một đối tượng sử dụng phụ thuộc vào kiểu dữ liệu của nó.

Vì chúng ta thường truy cập bộ nhớ thông qua tên biến (chứ không phải trực tiếp qua địa chỉ bộ nhớ), trình biên dịch có thể ẩn giấu chi tiết về số byte mà một đối tượng nhất định sử dụng khỏi chúng ta. Khi chúng ta truy cập một biến `x`, trình biên dịch biết cần truy xuất bao nhiêu byte dữ liệu (dựa trên kiểu của biến `x`), và có thể xử lý nhiệm vụ đó cho chúng ta.

Mặc dù vậy, việc biết một đối tượng sử dụng bao nhiêu bộ nhớ vẫn có ích vì một số lý do.

1. **Dung lượng lưu trữ:**

    Càng nhiều bộ nhớ một đối tượng sử dụng, thì nó càng chứa được nhiều thông tin.\
    1 bit có thể chứa 2 giá trị khả dĩ, `0` hoặc `1`:
    >**Bit 0**<br>
    >`0`\
    >`1`

    2 bit có thể chứa 4 giá trị khả dĩ:
    >**Bit 0**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**Bit 1**\
    >`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`\
    >`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`\
    >`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`\
    >`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`

    3 bit có thể chứa 8 giá trị khả dĩ:
    >**Bit 0**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**Bit 1**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**Bit 2**\
    >`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`\
    >`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`\
    >`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`\
    >`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`\
    >`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`\
    >`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`\
    >`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`0`\
    >`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`1`

    Nói chung, một đối tượng có **n** bit (n là một số nguyên) có thể chứa **2<sup>n</sup>** (2 mũ n, cũng thường được viết là 2^n) giá trị duy nhất. Do đó, với một byte 8 bit, một đối tượng có kích thước byte có thể chứa 2<sup>8</sup> (256) giá trị khác nhau. Một đối tượng sử dụng 2 byte có thể chứa 2<sup>16</sup> (65536) giá trị khác nhau!

    Do đó, kích thước của đối tượng đặt ra giới hạn cho lượng giá trị duy nhất mà nó có thể lưu trữ - các đối tượng sử dụng nhiều byte hơn có thể lưu trữ một số lượng giá trị duy nhất lớn hơn. Chúng ta sẽ tìm hiểu thêm về điều này khi nói về số nguyên.
2. **Bộ nhớ hữu hạn:**

    Máy tính có một lượng bộ nhớ trống hữu hạn. Mỗi lần chúng ta định nghĩa một đối tượng, một phần nhỏ của bộ nhớ trống đó được sử dụng miễn là đối tượng tồn tại. Do máy tính hiện đại có rất nhiều bộ nhớ, nên tác động này thường không đáng kể. Tuy nhiên, đối với các chương trình cần một lượng lớn đối tượng hoặc dữ liệu (ví dụ: trò chơi đang render hàng triệu đa giác), thì sự khác biệt giữa sử dụng đối tượng 1 byte và 8 byte có thể rất đáng kể.

>**Điểm mấu chốt**<br>
>Lập trình viên mới thường quá chú trọng vào việc tối ưu hóa code để sử dụng ít bộ nhớ nhất có thể. Trong hầu hết các trường hợp, điều này không tạo ra sự khác biệt đáng kể. Hãy tập trung vào việc viết code dễ bảo trì và chỉ tối ưu hóa khi nào và ở đâu lợi ích thực sự cần thiết.

### **Kích thước kiểu dữ liệu cơ bản** 

Câu hỏi hiển nhiên tiếp theo là: **"Các biến có kiểu dữ liệu khác nhau chiếm bao nhiêu bộ nhớ?".**

Có lẽ điều ngạc nhiên là tiêu chuẩn C++ không định nghĩa kích thước chính xác (theo bit) cho bất kỳ kiểu dữ liệu cơ bản nào. Kiểu `char` phải là 1 byte, nhưng không có giả định rằng một byte bằng 8 bit. Các kiểu giống số nguyên (integral types) có kích thước tối thiểu (theo bit), nhưng có thể lớn hơn.

Trong loạt bài hướng dẫn này, chúng ta sẽ sử dụng cách nhìn đơn giản hóa, bằng cách đưa ra một số giả định hợp lý thường đúng cho các kiến trúc hiện đại:
- Một byte bằng 8 bit.
- Bộ nhớ được寻truy xuất theo byte, do đó đối tượng nhỏ nhất là 1 byte.
- Hỗ trợ dấu phẩy động tuân thủ theo chuẩn IEEE-754.
- Chúng ta đang sử dụng kiến trúc 32 bit hoặc 64 bit.

Dựa vào những điều kiện trên, chúng ta có thể xác định kích thước của các kiểu dữ liệu cơ bản như sau:

| Mục                        | Kiểu dữ liệu     | Kích thước tối thiểu | Kích thước tiêu chuẩn | Ghi chú               |
|----------------------------|------------------|----------------------|-----------------------|-----------------------|
| Boolean (logic)            | `bool`           | 1 byte               | 1 byte                |                       |
| Kí tự                      | `char`           | 1 byte               | 1 byte                | luôn chính xác 1 byte |
|                            | `wchar_t`        | 1 byte               | 2 hoặc 4 byte         |                       |
|                            | `char8_t`        | 1 byte               | 1 byte                |                       |
|                            | `char16_t`       | 2 byte               | 2 byte                |                       |
|                            | `char32_t`       | 4 byte               | 4 byte                |                       |
| Số nguyên                  | `short`          | 2 byte               | 2 byte                |                       |
|                            | `int`            | 2 byte               | 4 byte                |                       |
|                            | `long`           | 4 byte               | 4 hoặc 8 byte         |                       |
|                            | `long long`      | 8 byte               | 8 byte                |                       |
| So thập phân dấu phẩy động | `float`          | 4 byte               | 4 byte                |                       |
|                            | `double`         | 8 byte               | 8 byte                |                       |
|                            | `long double`    | 8 byte               | 8, 12 hoặc 16 byte    |                       |
| Con trỏ                    | `std::nullptr_t` | 4 byte               | 4 hoặc 8 byte         |                       |

>**Mẹo**<br>
>Để đạt được khả năng di động tối đa (chạy được trên nhiều nền tảng khác nhau), bạn không nên giả định rằng các biến có kích thước lớn hơn kích thước tối thiểu được quy định.<br>
>Mặt khác, nếu bạn muốn giả định một kiểu dữ liệu có kích thước nhất định (ví dụ: kiểu `int` có ít nhất 4 byte), bạn có thể sử dụng `static_assert` để yêu cầu trình biên dịch báo lỗi khi biên dịch trên một kiến trúc không đáp ứng giả định này. Chúng ta sẽ tìm hiểu cách thực hiện việc này trong bài học 9.6 - `assert` và `static_assert`.

>**Nội dung liên quan**<br>
>Nếu bạn đang sử dụng C++ trên một hệ thống không tuân theo các giả định của chúng tôi, hoặc chỉ đơn giản là tò mò, bạn có thể tìm thêm thông tin về những gì tiêu chuẩn C++ nói về kích thước tối thiểu của các kiểu dữ liệu khác nhau [ở đây](https://en.cppreference.com/w/cpp/language/types).

### **Toán tử sizeof**

Để xác định kích thước của các kiểu dữ liệu trên một máy cụ thể, C++ cung cấp một toán tử tên là `sizeof`. Toán tử `sizeof` là toán tử đơn ngôi nhận một kiểu dữ liệu hoặc một biến và trả về kích thước của nó theo byte. Bạn có thể biên dịch và chạy chương trình sau để xem một số kiểu dữ liệu của bạn có kích thước bao nhiêu:

>```
>#include <iomanip> // để sử dụng std::setw (hàm này thiết lập độ rộng của đầu ra tiếp theo)
>#include <iostream>
>
>int main()
>{
>    std::cout << std::left; // canh chỉnh đầu ra sang trái
>    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
>    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
>    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
>    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
>    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
>    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
>    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
>    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
>    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";
>
>    return 0;
>}

Kết quả đầu ra trên máy của tác giả:
>```
>bool:           1 bytes
>char:           1 bytes
>short:          2 bytes
>int:            4 bytes
>long:           4 bytes
>long long:      8 bytes
>float:          4 bytes
>double:         8 bytes
>long double:    8 bytes

Lưu ý rằng kết quả của bạn có thể khác nhau tùy thuộc vào trình biên dịch, kiến trúc máy tính, hệ điều hành, cài đặt biên dịch (32-bit vs 64-bit), v.v.

Sử dụng `sizeof` trên kiểu dữ liệu không đầy đủ sẽ dẫn đến lỗi biên dịch. Ví dụ, sử dụng `sizeof` trên `void` sẽ gây ra lỗi.

Bạn cũng có thể sử dụng toán tử `sizeof` trên tên biến:
>```
>#include <iostream>
>
>int main()
>{
>    int x{};
>    std::cout << "x is " << sizeof(x) << " bytes\n";
>
>    return 0;
>}
>```

**Kết quả:**
>```
>x is 4 bytes
>```

>**Đối với người đọc nâng cao:**
>`sizeof` không bao gồm bộ nhớ được cấp phát động được sử dụng bởi một đối tượng. Chúng tôi sẽ thảo luận về cấp phát bộ nhớ động trong một bài học sau.

### **Hiệu suất của kiểu dữ liệu cơ bản:**

Trên các máy tính hiện đại, các đối tượng của các kiểu dữ liệu cơ bản hoạt động nhanh, vì vậy hiệu suất khi sử dụng hoặc sao chép các kiểu này thường không cần quan tâm.

>**Ngoài lề**<br>
>Bạn có thể cho rằng các kiểu dữ liệu sử dụng ít bộ nhớ sẽ nhanh hơn các kiểu dữ liệu sử dụng nhiều bộ nhớ. Điều này không luôn luôn đúng. CPU thường được tối ưu hóa để xử lý dữ liệu có kích thước nhất định (ví dụ: 32 bit) và các kiểu dữ liệu phù hợp với kích thước đó có thể được xử lý nhanh hơn. Trên một máy tính như vậy, kiểu `int` 32 bit có thể nhanh hơn kiểu `short` 16 bit hoặc `char` 8 bit.
