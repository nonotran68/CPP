## **Bài 4.1: <u>Giới thiệu về Kiểu dữ liệu cơ bản</u>**

### **Bit, Byte và Địa chỉ bộ nhớ**

Trong bài học [**1.3 - Giới thiệu về đối tượng và biến**](../lesson1/lesson1_3.ipynb), chúng ta đã đề cập đến việc biến là tên gọi của một vùng nhớ được sử dụng để lưu trữ thông tin. Nhắc lại một cách ngắn gọn, máy tính có bộ nhớ truy cập ngẫu nhiên (**RAM**) mà các chương trình có thể sử dụng. Khi một biến được khai báo, một phần của bộ nhớ đó được dành riêng cho biến đó.

Đơn vị nhỏ nhất của bộ nhớ là một **bit** (còn gọi là **binary digit** hay đơn vị nhị phân), có thể chứa giá trị 0 hoặc 1. Bạn có thể coi một bit giống như công tắc đèn truyền thống - đèn tắt (0) hoặc bật (1). Không có trạng thái trung gian nào. Nếu bạn nhìn vào một đoạn bộ nhớ ngẫu nhiên, tất cả những gì bạn thấy là `...011010100101010...` hoặc một tổ hợp nào đó tương tự.

Bộ nhớ được tổ chức thành các đơn vị tuần tự được gọi là **địa chỉ bộ nhớ** (hay ngắn gọn là **địa chỉ**). Tương tự như cách một địa chỉ đường phố có thể được sử dụng để tìm một ngôi nhà nhất định trên một con phố, **địa chỉ bộ nhớ** cho phép chúng ta tìm và truy cập nội dung của bộ nhớ tại một vị trí cụ thể.

Có lẽ điều ngạc nhiên là, trong kiến trúc máy tính hiện đại, mỗi bit không có địa chỉ bộ nhớ riêng biệt. Điều này là do số lượng địa chỉ bộ nhớ bị hạn chế và nhu cầu truy cập dữ liệu từng bit là rất hiếm. Thay vào đó, mỗi địa chỉ bộ nhớ chứa 1 **byte** dữ liệu. **Byte** là một nhóm các bit được vận hành như một đơn vị. Tiêu chuẩn hiện đại là **1 byte** bao gồm **8 bit** tuần tự.

>**Kiến thức cốt lõi:**<br>
>Trong C++, chúng ta thường làm việc với các khối dữ liệu có kích thước bằng **byte**.

Hình ảnh sau đây cho thấy một số địa chỉ bộ nhớ tuần tự, cùng với byte dữ liệu tương ứng:
>![](MemoryAddresses.png)


>**Ngoài lề**<br>
>Một số máy cũ hoặc không theo tiêu chuẩn có thể có byte với kích thước khác nhau (từ 1 đến 48 bit) - tuy nhiên, chúng ta thường không cần lo lắng về những điều này, vì tiêu chuẩn thực tế hiện đại là 1 byte bằng 8 bit. Trong các bài hướng dẫn này, chúng ta sẽ giả sử 1 byte bằng 8 bit.

### **Kiểu dữ liệu**

Vì tất cả dữ liệu trên máy tính chỉ là một dãy bit, chúng ta sử dụng **kiểu dữ liệu** (thường được gọi tắt là **"kiểu"**) để báo cho trình biên dịch cách giải thích nội dung của bộ nhớ theo một cách có ý nghĩa. Bạn đã thấy một ví dụ về kiểu dữ liệu: *số nguyên*. Khi chúng ta khai báo một biến là kiểu số nguyên, chúng ta đang nói với trình biên dịch "phần bộ nhớ mà biến này sử dụng sẽ được giải thích là một giá trị số nguyên".

Khi bạn gán giá trị cho một đối tượng, trình biên dịch và CPU sẽ xử lý việc mã hóa giá trị của bạn thành chuỗi bit thích hợp cho kiểu dữ liệu đó, sau đó được lưu trữ trong bộ nhớ (nhớ rằng: bộ nhớ chỉ có thể lưu trữ bit). Ví dụ, nếu bạn gán cho một đối tượng kiểu số nguyên giá trị `65`, thì giá trị đó được chuyển đổi thành chuỗi bit `01000001` và được lưu trữ trong bộ nhớ được gán cho đối tượng.

Ngược lại, khi đối tượng được đánh giá để tạo ra một giá trị, chuỗi bit đó được khôi phục lại thành giá trị ban đầu. Nghĩa là `01000001` được chuyển đổi trở lại thành giá trị `65`.

May mắn thay, trình biên dịch và CPU thực hiện tất cả các công việc khó khăn ở đây, vì vậy bạn thường không cần lo lắng về cách các giá trị được chuyển đổi thành chuỗi bit và ngược lại.

Tất cả bạn cần làm là chọn một kiểu dữ liệu cho đối tượng phù hợp nhất với việc sử dụng bạn muốn.



### **Kiểu dữ liệu cơ bản**

C++ cung cấp sẵn hỗ trợ cho nhiều kiểu dữ liệu khác nhau. Chúng được gọi là **kiểu dữ liệu cơ bản (fundamental data types)**, nhưng thường được gọi không chính thức là **kiểu cơ bản (basic types)**, **kiểu nguyên thủy (primitive types)** hoặc **kiểu dựng sẵn (built-in types)**.

Dưới đây là danh sách các kiểu dữ liệu cơ bản, một số trong số đó bạn đã từng gặp:

| Kiểu dữ liệu                                                                                    | Phân loại             | Ý nghĩa                                    | Ví dụ     |
|--------------------------------------------------------------------------------------------|-----------------------|--------------------------------------------|-----------|
| `float`<br><br>`double`<br><br>`long double`                                                     | Số thực dấu phẩy động | Đi kèm với phần thập phân sau dấu phẩy (chấm)     | `3.1415926` |
| `bool`                                                                                       | Integral (Logic)     | Đúng (true) hoặc sai (false)                             | `true`      |
| `char`<br><br>`wchar_t`<br><br>`char8_t` (C++20)<br><br>`char16_t` (C++11)<br><br>`char32_t` (C++11) |Integral (ký tự)     | Một ký tự trong bảng chữ cái               | `'c'`<br>   |
| `short int`<br><br>`int`<br><br>`long int`<br><br>`long long int` (C++11)                          | Số nguyên (integer)            | Số nguyên âm và số nguyên dương bao gồm 0 | 64        |
| `std::nullptr_t` (C++11)                                                                     | Con trỏ null          | Con trỏ null                               | `nullptr`   |
| `void`                                                                                       | Void                  | Không có kiểu                              | `void`      |

Chương này tập trung khám phá chi tiết các kiểu dữ liệu cơ bản (ngoại trừ `std::nullptr_t`, kiểu này sẽ được thảo luận khi chúng ta nói về con trỏ). C++ cũng hỗ trợ một số kiểu dữ liệu phức tạp hơn, được gọi là **kiểu phức hợp** (compound types). Chúng ta sẽ tìm hiểu về kiểu phức hợp trong một chương học sắp tới.

>**Lưu ý của tác giả:**<br>
>Các thuật ngữ *integer* (số nguyên) và *integral* (thuộc loại số nguyên) có vẻ tương đồng nhưng đôi khi lại có ý nghĩa khác nhau.
>- Trong toán học, *integer* là một số không có phần thập phân hoặc phần phân số, bao gồm cả số âm, số dương và số 0.
>- Trong C++, thuật ngữ *integer* thường được dùng để chỉ kiểu dữ liệu `int`, lưu trữ các giá trị số nguyên. Tuy nhiên, đôi khi nó cũng được dùng để chỉ một tập hợp rộng hơn các kiểu dữ liệu thường được sử dụng để lưu trữ và hiển thị các giá trị số nguyên. Điều này bao gồm `short`, `int`, `long`, `long long` và các biến thể có dấu và không dấu của chúng.
>- Thuật ngữ *integral* có nghĩa là **"giống như số nguyên"**. Thường thì *integral* được sử dụng như một phần của cụm từ "kiểu thuộc loại số nguyên", bao gồm tập hợp rộng hơn các kiểu được lưu trữ trong bộ nhớ dưới dạng số nguyên, mặc dù hành vi của chúng có thể khác nhau (chúng ta sẽ thấy chi tiết hơn trong chương này khi nói về các kiểu ký tự `char`). Điều này bao gồm `bool`, các kiểu số nguyên và tất cả các kiểu ký tự khác nhau.

>**Ngoài lề**<br>
>Hầu hết các ngôn ngữ lập trình hiện đại đều bao gồm một kiểu dữ liệu cơ bản là `string` (chuỗi ký tự là một kiểu dữ liệu cho phép chúng ta lưu trữ một dãy các ký tự, thường được dùng để biểu diễn văn bản). Trong C++, `string` không phải là một kiểu dữ liệu cơ bản (mà là một kiểu phức hợp). Nhưng vì cách sử dụng cơ bản của `string` khá đơn giản và hữu ích, nên chúng ta sẽ giới thiệu về chuỗi trong chương tiếp theo (bài học 5.9 - Giới thiệu về `std::string`).

### **Hậu tố `_t`**

Nhiều kiểu dữ liệu được định nghĩa trong các phiên bản C++ mới hơn (ví dụ `std::nullptr_t`) sử dụng hậu tố `_t`. Hậu tố này có nghĩa là **"kiểu" (type)**, và đây là một thuật ngữ phổ biến được áp dụng cho các kiểu dữ liệu hiện đại.

Nếu bạn thấy một cái gì đó có hậu tố `_t`, thì có thể nó là một kiểu dữ liệu. Nhưng nhiều kiểu dữ liệu không có hậu tố `_t`, vì vậy điều này không được áp dụng một cách nhất quán.

## **Bài 4.2: <u>`void`</u>** 

### **`void` - Kiểu dữ liệu đơn giản nhất**

`void` là một trong những kiểu dữ liệu dễ giải thích nhất. Về cơ bản, `void` có nghĩa là **"không kiểu"**!

`void` là ví dụ đầu tiên về một **kiểu dữ liệu không đầy đủ (incomplete type)**. **Kiểu dữ liệu không đầy đủ** là kiểu đã được khai báo nhưng chưa được định nghĩa. Trình biên dịch biết về sự tồn tại của các kiểu như vậy, nhưng không có đủ thông tin để xác định cần phân bổ bao nhiêu bộ nhớ cho các đối tượng của kiểu đó. `void` được thiết kế là không đầy đủ vì nó đại diện cho sự thiếu kiểu, do đó không thể được định nghĩa.

**Kiểu dữ liệu không đầy đủ không thể được khởi tạo:**
>```
>void value; // Không hợp lệ, biến không thể được khai báo với kiểu không đầy đủ void
>```

**`void` thường được sử dụng trong một số ngữ cảnh khác nhau:**

### **Hàm không trả về giá trị**

Thông thường nhất, `void` được sử dụng để chỉ rằng một hàm không trả về giá trị:

>```
>void writeValue(int x) // void ở đây nghĩa là không có giá trị trả về
>{
>    std::cout << "Giá trị của x là: " << x << '\n';
>    // Không có lệnh return, vì hàm này không trả về giá trị
>}
>```

Nếu bạn sử dụng lệnh `return` để cố gắng trả về giá trị trong một hàm như vậy, sẽ dẫn đến lỗi biên dịch:

>```
>void noReturn(int x) // void ở đây nghĩa là không có giá trị trả về
>{
>    std::cout << "Giá trị của x là: " << x << '\n';
>
>    return 5; // Lỗi
>}
>```

Trên Visual Studio 2017, lỗi này sẽ hiển thị:
>```
>error C2562: 'noReturn': 'void' function returning a value
>```

### **Không khuyến khích: Hàm không nhận tham số**

Trong C, `void` được sử dụng để chỉ rằng một hàm không nhận bất kỳ tham số nào:

>```
>int getValue(void) // void ở đây nghĩa là không có tham số
>{
>    int x{};
>    std::cin >> x;
>
>    return x;
>}
>```

Mặc dù đoạn code này có thể biên dịch trong C++ (vì lý do tương thích ngược), cách sử dụng từ khóa `void` này được coi là không khuyến khích trong C++. Đoạn code sau đây tương đương và được ưu tiên hơn trong C++:

>```
>int getValue() // Danh sách tham số trống ngầm định là void
>{
>    int x{};
>    std::cin >> x;
>
>    return x;
>}
>```

>**Thực hành tốt nhất:**<br>
>Sử dụng danh sách tham số trống thay vì `void` để chỉ rằng một hàm không có tham số.

### **Những cách sử dụng `void` khác**

Từ khóa `void` có cách sử dụng thứ ba (nâng cao hơn) trong C++, được đề cập trong phần 19.5 - Con trỏ `void`. Vì chúng ta chưa học về con trỏ, bạn không cần lo lắng về trường hợp này hiện tại.

Tiếp tục nào!

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
- Bộ nhớ được truy xuất theo byte, do đó đối tượng nhỏ nhất là 1 byte.
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

### **Toán tử `sizeof`**

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

## **Bài 4.4: <u>Số nguyên có dấu</u>** 

**Số nguyên (integer)** là một kiểu dữ liệu nguyên có thể biểu diễn các số nguyên dương, âm và số 0 (ví dụ: `-2`, `-1`, `0`, `1`, `2`). C++ cung cấp 4 kiểu số nguyên cơ bản chính để sử dụng:

| Kiểu        | Kích thước tối thiểu | Ghi chú                                      |
|-------------|----------------------|----------------------------------------------|
| `short`     | 16 bits              |                                              |
| `int`       | 16 bits              | Thường là 32 bit trên các kiến trúc hiện đại |
| `long`      | 32 bits              |                                              |
| `long long` | 64 bits              |                                              |

Sự khác biệt chính giữa các kiểu số nguyên khác nhau là kích thước của chúng - các số nguyên lớn hơn có thể chứa các số lớn hơn.

>**Lưu ý:**<br>
>C++ chỉ đảm bảo rằng các số nguyên sẽ có một kích thước tối thiểu nhất định, chứ không đảm bảo chúng sẽ có một kích thước cụ thể. Xem bài học [**4.3 - Kích thước đối tượng và toán tử `sizeof`**](lesson4_3.ipynb) để biết thông tin về cách xác định kích thước của mỗi kiểu trên máy tính của bạn.

>**Ngoài lề:**<br>
>Về mặt kỹ thuật, các kiểu `bool` và `char` được coi là các kiểu nguyên (bởi vì các kiểu này lưu trữ giá trị của chúng dưới dạng giá trị nguyên). Trong một bài học tiếp theo, chúng tôi sẽ loại trừ các kiểu này khỏi bài thảo luận.

### **Số nguyên có dấu**

Trong cuộc sống hàng ngày, khi muốn viết các số âm, chúng ta sử dụng **dấu trừ**. Ví dụ, `-3` có nghĩa là "âm 3". Chúng ta cũng thường hiểu `+3` là "dương 3" (mặc dù theo quy ước thông thường, chúng ta thường bỏ qua tiền tố cộng).

Thuộc tính là dương, âm hay bằng 0 này được gọi là dấu của số.

Theo mặc định, các số nguyên trong C++ là có dấu, nghĩa là dấu của số được lưu trữ như một phần của số. Do đó, một số nguyên có dấu có thể chứa cả số dương, số âm và số 0.

Trong bài học này, chúng ta sẽ tập trung vào các số nguyên có dấu. Chúng ta sẽ thảo luận về các số nguyên không dấu (chỉ có thể chứa các số không âm) trong bài học tiếp theo.

>**Nội dung liên quan**<br>
>Trong biểu diễn nhị phân, một bit duy nhất (gọi là bit dấu) được sử dụng để lưu trữ dấu của số. Các bit không dấu (gọi là bit trị tuyệt đối) xác định giá trị tuyệt đối của số.
>
>Chúng ta sẽ thảo luận về cách sử dụng bit dấu khi biểu diễn số trong nhị phân trong bài học O.4 - Chuyển đổi số nguyên giữa biểu diễn nhị phân và thập phân.

### **Định nghĩa số nguyên có dấu**

Đây là cách ưa thích để định nghĩa bốn kiểu số nguyên có dấu:

>```
>short s;      // ưu tiên "short" thay vì "short int"
>int i;
>long l;       // ưu tiên "long" thay vì "long int"
>long long ll; // ưu tiên "long long" thay vì "long long int"
>
Mặc dù `short int`, `long int`, hoặc `long long int` đều hoạt động, chúng ta thích sử dụng các tên viết tắt cho các kiểu này (không sử dụng hậu tố `int`). Ngoài việc gõ phím ít hơn, việc thêm hậu tố `int` khiến kiểu dữ liệu khó phân biệt hơn với các biến kiểu `int`. Điều này có thể dẫn đến sai lầm nếu vô tình bỏ qua các từ sửa đổi `short` hoặc `long`.

Các kiểu số nguyên cũng có thể sử dụng từ khóa `signed` tùy chọn, theo quy ước, thường được đặt trước tên kiểu:

>```
>signed short ss;
>signed int si;
>signed long sl;
>signed long long sll;
>```

Tuy nhiên, từ khóa này không nên được sử dụng vì nó là thừa, vì các số nguyên có dấu theo mặc định.

>**Thực hành tốt nhất**<br>
Ưu tiên các kiểu viết tắt không sử dụng hậu tố `int` hoặc tiền tố `signed`.

### **Phạm vi của số nguyên có dấu**

Như bạn đã học được trong phần trước, một biến có **n bit** có thể chứa **2<sup>n</sup>** giá trị khả thi. Nhưng các giá trị cụ thể nào? Chúng ta gọi tập hợp các giá trị cụ thể mà một kiểu dữ liệu có thể chứa là phạm vi của nó. Phạm vi của một biến số nguyên được xác định bởi hai yếu tố: kích thước của nó (theo bit) và nó có dấu hay không.

Theo định nghĩa, một số nguyên có dấu **8 bit** có phạm vi từ `-128` đến `127`. Điều này có nghĩa là một số nguyên có dấu có thể lưu trữ an toàn bất kỳ giá trị số nguyên nào giữa `-128` và `127` (bao gồm cả giá trị cuối).

>**Ngoài lề:**<br>
>*Math time:* một số nguyên 8 bit chứa 8 bit. 2<sup>8</sup> là 256, do đó một số nguyên 8 bit có thể chứa 256 giá trị khả thi. Có 256 giá trị khả thi giữa `-128` đến `127`, bao gồm cả giá trị đầu mút.\
>7 bit được sử dụng để chứa giá trị tuyệt đối của số, và 1 bit được sử dụng để chứa dấu.

Bảng dưới đây chứa phạm vi của các số nguyên có dấu có kích thước khác nhau:

| Kích thước/Kiểu | Phạm vi                                                  |
|-----------------|----------------------------------------------------------|
| 8 bit signed    | -128 đến 127                                             |
| 16 bit signed   | -32,768 đến 32,767                                       |
| 32 bit signed   | -2,147,483,648 đến 2,147,483,647                         |
| 64 bit signed   | -9,223,372,036,854,775,808 đến 9,223,372,036,854,775,807 |

Đối với những người thích toán học, một biến có dấu **n-bit** có phạm vi từ **-2<sup>n-1</sup> đến 2<sup>n-1</sup>-1**.

Đối với những người không thích toán học... hãy sử dụng bảng. :)

### **Tràn số (Overflow)**

Điều gì xảy ra nếu chúng ta cố gắng gán giá trị `140` cho một số nguyên có dấu 8 bit? Số này nằm ngoài phạm vi mà một số nguyên có dấu 8 bit có thể chứa. Số `140` cần 9 bit để biểu diễn (8 bit giá trị tuyệt đối và 1 bit dấu), nhưng chúng ta chỉ có 8 bit (7 bit giá trị tuyệt đối và 1 bit dấu) khả dụng trong một số nguyên có dấu 8 bit.

Tiêu chuẩn **C++20** đưa ra tuyên bố bao quát này:\
"Nếu trong quá trình tính toán một biểu thức, kết quả không được xác định về mặt toán học hoặc không nằm trong phạm vi các giá trị có thể biểu diễn cho kiểu của nó, thì hành vi đó là hành vi bất định".\
Theo diễn giải thông thường, điều này được gọi là **tràn số (overflow)**.

Do đó, việc gán giá trị `140` cho một số nguyên có dấu 8 bit sẽ dẫn đến hành vi bất định.

Nếu một phép toán số học (như cộng hoặc nhân) cố gắng tạo ra một giá trị nằm ngoài phạm vi có thể biểu diễn được, thì điều này được gọi là **tràn số nguyên (integer overflow)** (hoặc **tràn số học**). Đối với các số nguyên có dấu, **tràn số nguyên** sẽ dẫn đến **hành vi bất định**.

>```
>#include <iostream>
>
>int main()
>{
>    // Giả sử số nguyên chiếm 4 byte
>    int x { 2'147'483'647 }; // giá trị tối đa của một số nguyên có dấu 4 byte
>    std::cout << x << '\n';
>
>    x = x + 1; // tràn số nguyên, hành vi không xác định
>    std::cout << x << '\n';
>
>    return 0;
>}
>```

Trên máy của tác giả, mã trên in ra:
>```
>2147483647
>-2147483648
>```

Tuy nhiên, vì kết quả thứ hai là kết quả của hành vi bất định, nên giá trị xuất ra có thể thay đổi trên máy của bạn.

>**Đối với người đọc nâng cao**<br>
Chúng ta sẽ đề cập về những gì xảy ra khi số nguyên không dấu bị tràn trong bài học 4.5 - Số nguyên không dấu và lý do tại sao nên tránh chúng.

Nhìn chung, tràn số dẫn đến mất thông tin, điều này hầu như không mong muốn. Nếu có bất kỳ nghi ngờ nào rằng một đối tượng có thể cần lưu trữ một giá trị nằm ngoài phạm vi của nó, hãy sử dụng một kiểu dữ liệu có phạm vi lớn hơn!

### **Phép chia số nguyên**

Khi chia hai số nguyên, C++ hoạt động như chúng ta mong đợi khi thương là một số nguyên:
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << 20 / 4 << '\n';
>    return 0;
>}
>```

Điều này tạo ra kết quả mong đợi:
>`5`

Nhưng hãy xem điều gì xảy ra khi phép chia số nguyên tạo ra kết quả là một số thập phân:
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << 8 / 5 << '\n';
>    return 0;
>}
>```

Điều này có thể tạo ra một kết quả không mong đợi:
>`1`

Khi thực hiện phép chia với hai số nguyên (được gọi là **phép chia số nguyên**), C++ luôn tạo ra một **kết quả nguyên**. Vì các số nguyên không thể chứa các giá trị thập phân, bất kỳ phần thập phân nào cũng đơn giản bị loại bỏ (không được làm tròn!).

Xem xét kỹ hơn ví dụ trên, `8 / 5` cho ra giá trị `1.6`. Phần thập phân (`0.6`) bị loại bỏ và kết quả là `1`. Ngoài ra, chúng ta có thể nói `8 / 5` bằng `1` dư `3`. Số dư bị loại bỏ, chỉ còn `1`.

Tương tự, `-8 / 5` cho ra giá trị `-1`.

>**Cảnh báo**<br>
>Hãy cẩn thận khi sử dụng phép chia số nguyên, vì bạn sẽ mất bất kỳ phần thập phân nào của thương. Tuy nhiên, nếu đó là điều bạn muốn, phép chia số nguyên là an toàn để sử dụng vì kết quả có thể dự đoán được.

>Nếu cần kết quả thập phân, chúng tôi sẽ hướng dẫn phương pháp thực hiện việc này trong bài học 6.2 - Toán tử số học.

### **Trắc nghiệm**

**Câu hỏi #1**<br>
Phạm vi của một số nguyên có dấu 5 bit sẽ là gì?

<details>
<summary><b>Lời giải:</b></summary>

Một số 5 bit có thể hỗ trợ 2<sup>5</sup> = 32 giá trị duy nhất. Đối với một số nguyên có dấu, chúng được chia gần bằng nhau giữa các số dương và âm, với số âm nhận thêm một giá trị. Vì vậy, phạm vi sẽ là từ `-16` đến `15`.

Một cách khác để suy nghĩ về điều này: 1 trong 5 bit được yêu cầu để chứa dấu. Điều đó còn lại 4 bit cho giá trị tuyệt đối. Với 4 bit, chúng ta có 16 giá trị duy nhất. Ở phía âm, các bit giá trị tuyệt đối này biểu diễn các giá trị từ `-1` đến `-16`. Ở phía không âm, các bit giá trị tuyệt đối này biểu diễn các giá trị từ `0` đến `15`. Phía không âm có phạm vi ít hơn một giá trị vì nó bao gồm `0`.
</details>

**Câu hỏi #2**<br>
***a***) Kết quả của `13 / 5` là gì?
<details>
<summary><b>Lời giải:</b></summary>

`13 / 5` = `2` dư `3`. Số dư bị loại bỏ, chỉ còn `2`.
</details>


***b***) Kết quả của `-13 / 5` là gì?
<details>
<summary><b>Lời giải:</b></summary>
    
`-13 / 5` = `-2` dư `-3`. Số dư bị loại bỏ, chỉ còn `-2`.
</details>

## **Bài 4.5: <u>Số nguyên không dấu (Unsigned integers) và tại sao nên tránh sử dụng chúng</u>**

### **Số nguyên không dấu**

Trong bài học trước ([**Bài 4.4: Số nguyên có dấu**](lesson4_4.ipynb)), chúng ta đã tìm hiểu về số nguyên có dấu, là một tập hợp các kiểu dữ liệu có thể chứa các số nguyên dương, âm và số 0.

C++ cũng hỗ trợ các số nguyên không dấu. Số nguyên không dấu là các số nguyên chỉ có thể chứa các số nguyên không âm.

### **Định nghĩa số nguyên không dấu**

Để định nghĩa một số nguyên không dấu, chúng ta sử dụng từ khóa `unsigned`. Theo quy ước, từ khóa này được đặt trước kiểu dữ liệu:

>```
>unsigned short us;
>unsigned int ui;
>unsigned long ul;
>unsigned long long ull;
>```

### **Phạm vi của số nguyên không dấu**

Một số nguyên không dấu 1 byte có phạm vi từ `0` đến `255`. So sánh điều này với phạm vi của số nguyên có dấu 1 byte là từ `-128` đến `127`. Cả hai đều có thể lưu trữ **256** giá trị khác nhau, nhưng số nguyên có dấu sử dụng một nửa phạm vi của chúng cho các số âm, trong khi số nguyên không dấu có thể lưu trữ các số dương lớn gấp đôi.

Bảng dưới đây hiển thị phạm vi của số nguyên không dấu:

| Kích thước/Kiểu | Phạm vi                          |
|-----------------|----------------------------------|
| 8 bit unsigned  | 0 đến 255                        |
| 16 bit signed   | 0 đến 65,535                     |
| 32 bit signed   | 0 đến 4,294,967,295              |
| 64 bit signed   | 0 đến 18,446,744,073,709,551,615 |p

Một biến không dấu **n-bit** có phạm vi từ **0** đến **2<sup>n</sup>-1**.

Số nguyên không dấu phù hợp cho các tình huống **không yêu cầu lưu trữ các số âm**, chẳng hạn như mạng và các hệ thống có ít bộ nhớ, vì số nguyên không dấu có thể lưu trữ nhiều số dương hơn mà không chiếm thêm bộ nhớ.

### **Lưu ý các thuật ngữ `signed` và `unsigned`**

Lập trình viên mới đôi khi bị nhầm lẫn giữa **`signed`** và **`unsigned`**. Dưới đây là một cách đơn giản để ghi nhớ sự khác biệt: để phân biệt các số âm với các số dương, chúng ta sử dụng dấu âm. Nếu không có dấu, chúng ta mặc định số đó là dương. Do đó, một **số nguyên có dấu** (signed integer) có thể **phân biệt** giữa **số dương** và **số âm**. Một **số nguyên không dấu** (unsigned integer) giả định tất cả các giá trị đều **dương**.

### **Tràn số nguyên không dấu (Unsigned integer overflow)**

Điều gì xảy ra nếu chúng ta cố gắng lưu trữ số `280` (yêu cầu 9 bit để biểu diễn) trong một số nguyên không dấu 1 byte (8 bit)? Câu trả lời là **tràn số** (overflow).

>**Lưu ý của tác giả**<br>
>Điều lạ là tiêu chuẩn C++ nói rõ ràng rằng: "Một phép toán liên quan đến toán hạng không dấu không bao giờ có thể bị tràn số". Điều này trái ngược với sự đồng thuận lập trình chung cho rằng tràn số nguyên bao gồm cả các trường hợp `signed` và `unsigned` [<sup>dẫn nguồn</sup>](https://en.wikipedia.org/wiki/Integer_overflow#Definition_variations_and_ambiguity). Cho rằng hầu hết các lập trình viên sẽ coi đây là tràn số, chúng tôi sẽ gọi đây là tràn số bất chấp tuyên bố ngược lại của tiêu chuẩn C++.

Nếu một giá trị không dấu nằm ngoài phạm vi, nó sẽ được chia cho (*giá trị lớn nhất kiểu đó* + 1) và chỉ giữ lại phần dư. (*phép modulo*)

Số `280` quá lớn để có thể chứa trong phạm vi 1 byte của chúng ta từ `0` đến `255`. (*giá trị lớn nhất kiểu này* + 1) là 256. Do đó, chúng ta chia `280` cho `256`, được kết quả là `1` dư `24`. Phần dư `24` là thứ được lưu trữ.

**Ví dụ về điều này khi sử dụng kiểu short 2 byte:**

>```
>#include <iostream>
>
>int main()
>{
>    unsigned short x{ 65535 }; // giá trị không dấu 16-bit lớn nhất có thể
>    std::cout << "x was: " << x << '\n';
>
>    x = 65536; // 65536 nằm ngoài phạm vi của chúng ta, vì vậy chúng ta có modulo wrap-around
>    std::cout << "x is now: " << x << '\n';
>
>    x = 65537; // 65537 nằm ngoài phạm vi của chúng ta, vì vậy chúng ta có modulo wrap-around
>    std::cout << "x is now: " << x << '\n';
>
>    return 0;
>}

Bạn nghĩ kết quả của chương trình này sẽ là gì?

(**Lưu ý:** Nếu bạn cố gắng biên dịch chương trình trên, trình biên dịch của bạn sẽ đưa ra cảnh báo về tràn số hoặc cắt bớt - bạn sẽ cần tắt *"Treat warnings as errors"* để chạy chương trình)
>```
>x was: 65535
>x is now: 0
>x is now: 1
>```

Cũng có thể tràn số theo hướng khác. `0` có thể được biểu diễn trong một số nguyên không dấu 2 byte, vì vậy điều đó ổn. `-1` không thể biểu diễn được, vì vậy nó sẽ cuộn tròn lên đầu phạm vi, tạo ra giá trị `65535`. `-2` cuộn tròn thành `65534`. Và cứ thế.

>```
>#include <iostream>
>
>int main()
>{
>    unsigned short x{ 0 }; // giá trị không dấu 2-byte nhỏ nhất có thể
>    std::cout << "x was: " << x << '\n';
>
>    x = -1; // -1 nằm ngoài phạm vi của chúng ta, vì vậy chúng ta có modulo wrap-around
>    std::cout << "x is now: " << x << '\n';
>
>    x = -2; // -2 nằm ngoài phạm vi của chúng ta
>```

**Kết quả:**
>```
>x was: 0
>x is now: 65535
>x is now: 65534
>```

>**Ngoài lề**<br>
>Nhiều lỗi nghiêm trọng trong lịch sử trò chơi điện tử xảy ra do hành vi "wrap-around" (modulo wrapping) với số nguyên không dấu. Trong trò chơi arcade Donkey Kong, không thể vượt qua level 22 do lỗi tràn số khiến người chơi không đủ thời gian thưởng để hoàn thành level.
>
>Trong game PC Civilization, Gandhi nổi tiếng là người đầu tiên sử dụng vũ khí hạt nhân, điều này trái ngược với tính cách ôn hòa vốn có của ông. Theo giả thuyết của người chơi, ban đầu Gandhi được đặt mức độ hung hăng là 1. Tuy nhiên, nếu ông chọn chính phủ dân chủ, ông sẽ nhận được bộ điều chỉnh tính hung hăng -2 (giảm giá trị hung hăng hiện tại xuống 2). Điều này khiến mức độ hung hăng của Gandhi "chuyển thành giá trị đầu" thành 255, biến ông thành kẻ hung hăng tối đa! Tuy nhiên, Sid Meier (tác giả của trò chơi) đã đính chính rằng đây không phải là nguyên nhân thực sự dẫn đến hành vi này.

### **Tranh luận về số nguyên không dấu (Unsigned Integers)**

Nhiều lập trình viên (và cả một số công ty phát triển lớn như Google) cho rằng nên hạn chế sử dụng số nguyên không dấu.

Lý do chính cho khuyến cáo này là hai hành vi có thể gây ra vấn đề:
- Thứ nhất, với số nguyên có dấu, việc tràn số về giá trị tối đa hoặc tối thiểu (dương lớn nhất hoặc âm bé nhất) khó xảy ra hơn vì các giá trị này cách xa 0. Ngược lại, với số nguyên không dấu, tràn số về giá trị tối thiểu (`0`) rất dễ xảy ra bởi `0` thường gần với các giá trị hay dùng.

    **Ví dụ:** Hãy xem xét phép trừ hai số nguyên không dấu `2` và `3`:
    >```
    >#include <iostream>
    >// giả sử int là 4 byte
    >int main()
    >{
    >    unsigned int x{ 2 };
    >    unsigned int y{ 3 };
    >
    >    std::cout << x - y << '\n'; // in ra 4294967295 (sai!)
    >
    >    return 0;
    >}
    >```
    
    Chúng ta biết rằng `2 - 3` bằng `-1`, nhưng `-1` không thể biểu diễn được trong một số nguyên không dấu, nên xảy ra tràn số và kết quả là:
    >`4294967295`

    Một trường hợp "cuộn tròn" (wrap-around) không mong muốn khác xảy ra khi một số nguyên không dấu liên tục bị giảm `1` đơn vị cho đến khi nó cố gắng giảm xuống thành một số âm. Bạn sẽ thấy ví dụ về điều này khi tìm hiểu về vòng lặp.
- Thứ hai, và nguy hiểm hơn, là hành vi không mong muốn có thể xảy ra khi trộn lẫn số nguyên có dấu và số nguyên không dấu. Trong C++, nếu một phép toán (ví dụ toán học hoặc so sánh) có một số nguyên có dấu và một số nguyên không dấu, thì số nguyên có dấu thường sẽ được chuyển đổi thành số nguyên không dấu. Do đó, kết quả cũng sẽ là không dấu.

    **Ví dụ:**
    >```
    >#include <iostream>
    >
    >// giả sử int là 4 byte
    >int main()
    >{
    >    unsigned int u{ 2 };
    >    signed int s{ 3 };
    >
    >    std::cout << u - s << '\n'; // 2 - 3 = 4294967295
    >
    >    return 0;
    >}
    >```

    Trong trường hợp này, nếu `u` là số có dấu, kết quả chính xác sẽ được tạo ra. Nhưng vì `u` là không dấu, `s` sẽ được chuyển đổi thành không dấu và kết quả (`-1`) được coi là một giá trị không dấu. Do `-1` không thể lưu trữ trong một giá trị không dấu, nên xảy ra tràn số và tạo ra câu trả lời không mong đợi.

    **Đây là một ví dụ khác:**
    >```
    >#include <iostream>
    >
    >// giả sử int là 4 byte
    >int main()
    >{
    >    signed int s { -1 };
    >    unsigned int u { 1 };
    >
    >    if (s < u) // -1 được ngầm chuyển đổi thành 4294967295, và 4294967295 < 1 là sai
    >        std::cout << "-1 nhỏ hơn 1\n";
    >    else
    >        std::cout << "1 nhỏ hơn -1\n"; // lệnh này được thực thi
    >
    >    return 0;
    >}
    >```

    Chương trình này được viết tốt, biên dịch thành công và logic có vẻ hợp lý. Nhưng nó in ra câu trả lời sai. Mặc dù trình biên dịch sẽ cảnh báo bạn về sự không tương thích giữa số có dấu và không dấu trong trường hợp này, nhưng nó cũng sẽ tạo ra các cảnh báo tương tự cho các trường hợp khác không gặp vấn đề này (ví dụ: khi cả hai số đều dương), khiến việc phát hiện ra sự cố thực sự trở nên khó khăn.

>**Liên quan:**
>- Bạn có thể tìm hiểu thêm về các quy tắc chuyển đổi yêu cầu cả hai toán hạng của một số phép toán nhị phân phải cùng kiểu trong bài học 10.5 - Chuyển đổi số học (Arithmetic conversions).
>- Bài học 4.10 - Giới thiệu về câu lệnh if sẽ hướng dẫn về các câu lệnh if.


Ngoài ra còn các trường hợp rắc rối khác khó phát hiện

**Xem xét ví dụ sau:**
>```
>#include <iostream>
>
>// giả sử int là 4 byte
>void doSomething(unsigned int x)
>{
>    // Chạy một đoạn code x lần
>
>    std::cout << "x là " << x << '\n';
>}
>
>int main()
>{
>    doSomething(-1);
>
>    return 0;
>}
>```

Người viết hàm `doSomething()` mong đợi hàm này chỉ được gọi với các số dương. Nhưng hàm gọi nó lại truyền vào `-1` - rõ ràng là một sai lầm. Vậy điều gì xảy ra trong trường hợp này?

Tham số kiểu `signed` là `-1` được ngầm chuyển đổi thành một tham số kiểu `unsigned`. `-1` không nằm trong phạm vi của một số `unsigned`, vì vậy nó sẽ "cuộn tròn" thành `4294967295`. Sau đó, chương trình của bạn có thể hoạt động bất thường.

Vấn đề hơn nữa là việc ngăn chặn điều này xảy ra có thể rất khó. Trừ khi bạn đã cấu hình trình biên dịch cảnh báo mạnh mẽ về việc chuyển đổi `signed/unsigned` (và bạn nên làm vậy), trình biên dịch của bạn có thể sẽ không phàn nàn về điều này.

Tất cả các vấn đề này đều thường gặp, gây ra hành vi không mong đợi và khó tìm, ngay cả khi sử dụng các công cụ tự động được thiết kế để phát hiện các trường hợp có vấn đề.

Xét theo những điều trên, cách thực hành tốt nhất hơi gây tranh cãi mà chúng tôi sẽ ủng hộ là tránh sử dụng các kiểu `unsigned` ngoại trừ trong những trường hợp cụ thể.

>**Thực hành tốt nhất**
>- Ưu tiên sử dụng số signed hơn số unsigned để chứa các giá trị (ngay cả các giá trị đáng lẽ không âm) và các phép toán.
>- Tránh trộn lẫn các số signed và unsigned.

>**Tài liệu tham khảo**
>- [Interactive C++ panel](https://www.youtube.com/watch?v=_nrly6PH6NU) (xem [9:48-13:08], [41:06-45:26] và [1:02:50-1:03:15])
>- [Subscripts and sizes should be signed](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1428r0.pdf) (from Bjarne Stroustrup, the creator of C++)
>- [Unsigned integers from the libtorrent blog](https://blog.libtorrent.org/2016/05/unsigned-integers/)

### **Vậy khi nào bạn nên sử dụng số unsigned?**

Vẫn có một vài trường hợp trong C++ mà việc sử dụng số `unsigned` là ổn/cần thiết.

- Thứ nhất, số `unsigned` được ưu tiên hơn khi xử lý thao tác bit (được đề cập trong chương O - đó là ‘o’ hoa, không phải ‘0’). Chúng cũng hữu ích khi cần hành vi "cuộn tròn" được xác định rõ ràng (hữu ích trong một số thuật toán như mã hóa và tạo số ngẫu nhiên).

- Thứ hai, việc sử dụng số `unsigned` đôi khi vẫn không thể tránh khỏi, chủ yếu liên quan đến việc lập chỉ mục mảng (**array indexing**). Chúng tôi sẽ nói thêm về điều này trong các bài học về mảng và lập chỉ mục mảng.

- Ngoài ra, lưu ý rằng nếu bạn đang phát triển cho hệ thống nhúng (ví dụ: Arduino) hoặc một số bộ xử lý / bối cảnh hạn chế bộ nhớ khác, việc sử dụng số `unsigned` phổ biến hơn và được chấp nhận hơn (và trong một số trường hợp, không thể tránh khỏi) vì lý do hiệu suất.

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


## **Bài 4.7: <u>Giới thiệu về ký hiệu khoa học (scientific notation)</u>**

Trước khi đi vào chủ đề tiếp theo, chúng ta sẽ tìm hiểu sơ lược về ký hiệu khoa học.

**Ký hiệu khoa học** là một cách viết tắt hữu ích cho các số phức tạp theo dạng gọn hơn. Mặc dù thoạt nhìn ký hiệu khoa học có vẻ lạ, nhưng hiểu được ký hiệu khoa học sẽ giúp bạn hiểu cách các số thực hoạt động và quan trọng hơn, giới hạn của chúng là gì.

Số trong ký hiệu khoa học được viết theo dạng: *thừa số × 10<sup>số mũ</sup>*. 

Ví dụ, trong ký hiệu khoa học 1.2 x 10⁴, 1.2 là thừa số và 4 là số mũ. Vì 10⁴ bằng 10.000, nên 1.2 x 10⁴ bằng 12.000.

Theo quy ước, các số trong ký hiệu khoa học được viết với một chữ số trước dấu thập phân và các chữ số còn lại sau dấu thập phân.

Xét khối lượng của Trái Đất. Trong dạng thập phân, chúng ta sẽ viết nó là 5972200000000000000000000 kg. Đó là một con số thực sự lớn (quá lớn để chứa vừa trong một số nguyên 8 byte). Nó cũng khó đọc (có phải là 19 hay 20 số 0?). Ngay cả với dấu phân cách (5.972.200.000.000.000.000.000), con số vẫn khó đọc.

Trong ký hiệu khoa học, điều này sẽ được viết là 5.9722 x 10²⁴ kg, dễ đọc hơn nhiều. Ký hiệu khoa học có thêm lợi ích là giúp dễ dàng so sánh độ lớn của hai số cực lớn hoặc cực nhỏ chỉ đơn giản bằng cách so sánh số mũ.

Do việc gõ hoặc hiển thị số mũ trong C++ có thể khó khăn, chúng ta sử dụng ký tự *'e'* (hoặc đôi khi là *'E'*) để biểu diễn phần "nhân với 10 mũ" của phương trình. Ví dụ, 1.2 x 10⁴ sẽ được viết là `1.2e4`, và 5.9722 x 10²⁴ sẽ được viết là `5.9722e24`.

Đối với các số nhỏ hơn 1, số mũ có thể là âm. Số `5e-2` tương đương với 5 * 10⁻², bằng 5 / 10², hoặc 0.05. Khối lượng của một electron là `9.1093837e-31` kg.

### **Các chữ số có nghĩa**

Giả sử bạn cần biết giá trị của hằng số toán học *pi* cho một số phương trình, nhưng bạn đã quên. Bạn hỏi hai người. Một người nói với bạn giá trị của pi là 3.14. Người khác nói với bạn giá trị của pi là 3.14159. Cả hai giá trị này đều "chính xác", nhưng giá trị thứ hai chính xác hơn nhiều.

Đây là điều quan trọng nhất cần hiểu về ký hiệu khoa học: Các chữ số trong thừa số (phần trước dấu 'e') được gọi là các chữ số có nghĩa (hoặc chữ số có giá trị). Càng nhiều chữ số có nghĩa, thì số càng chính xác.

>**Lưu ý quan trọng**<br>
>Càng nhiều chữ số trong thừa số, thì số càng chính xác.

Trong ký hiệu khoa học, chúng ta sẽ viết 3.14 thành `3.14e0`. Vì có 3 số trong thừa số, nên số này có 3 chữ số có nghĩa.

3.14159 sẽ được viết thành `3.14159e0`. Vì có 6 số trong thừa số, nên số này có 6 chữ số có nghĩa.

### **Cách chuyển đổi số thập phân sang ký hiệu khoa học**

Thực hiện theo các bước sau để chuyển đổi số thập phân sang ký hiệu khoa học:
1. **Bắt đầu với số mũ bằng 0**.
2. **Di chuyển dấu thập phân sang trái hoặc phải** cho đến khi chỉ có một chữ số khác 0 ở bên trái dấu thập phân.
    - Mỗi lần bạn di chuyển dấu thập phân sang trái một vị trí, số mũ sẽ tăng thêm 1.
    - Mỗi lần bạn di chuyển dấu thập phân sang phải một vị trí, số mũ sẽ giảm đi 1.
3. **Xóa bỏ các số 0 ở đầu** (bên trái dấu thập phân) của thừa số (phần trước dấu "e").
4. **Xóa bỏ các số 0 ở cuối** (bên phải dấu thập phân) của thừa số chỉ khi số thập phân ban đầu không có dấu thập phân. Chúng tôi giả định rằng các số 0 này không có nghĩa. Nếu bạn có thêm thông tin cho thấy chúng có nghĩa, bạn có thể giữ lại chúng.

Ví dụ:
>```
>Bắt đầu với: 600.410
>Di chuyển dấu thập phân sang trái 2 vị trí: 6.00410e2
>Không có số 0 ở đầu để xóa: 6.00410e2
>Giữ lại các số 0 ở cuối: 6.00410e2 (có 6 chữ số có nghĩa)
>```

>```
>Bắt đầu với: 0.0078900
>Di chuyển dấu thập phân sang phải 3 vị trí: 0007.8900e-3
>Xóa bỏ số 0 dẫn đầu: 7.8900e-3
>Giữ lại các số 0 ở cuối: 7.8900e-3 (có 5 chữ số có nghĩa)
>```

>```
>Bắt đầu với: 42030 (không có thông tin cho thấy số 0 cuối cùng có nghĩa)
>Di chuyển dấu thập phân sang trái 4 vị trí: 4.2030e4
>Không có số 0 dẫn đầu để xóa: 4.2030e4
>Xóa bỏ số 0 ở cuối: 4.203e4 (có 4 chữ số có nghĩa)
>```

>```
>Bắt đầu với: 42030 (số 0 cuối cùng có nghĩa)
>Di chuyển dấu thập phân sang trái 4 vị trí: 4.2030e4
>Không có số 0 dẫn đầu để xóa: 4.2030e4
>Giữ lại các số 0 ở cuối: 4.2030e4 (có 5 chữ số có nghĩa)
>```

### **Xử lý các số 0 ở cuối (trailing zeros)**

Hãy xem xét trường hợp chúng ta yêu cầu hai trợ lý phòng thí nghiệm cùng cân một quả táo. Một người quay lại và nói quả táo nặng 87.0 gram. Người kia quay lại và nói quả táo nặng 87.000 gram. Giả sử cân nặng là chính xác. Trong trường hợp trước, trọng lượng thực tế của quả táo có thể nằm bất cứ đâu giữa 86.950 và 87.049 gram. Có thể cân chỉ chính xác đến phần mười gam gần nhất. Hoặc có thể trợ lý của chúng ta đã làm tròn một chút. Trong trường hợp thứ hai, chúng ta tin tưởng hơn nhiều về trọng lượng thực tế của quả táo (thực tế nó nặng từ 86.99950 đến 87.00049 gram, độ dao động ít hơn nhiều).

Khi chuyển đổi sang ký hiệu khoa học, các số 0 ở cuối sau dấu thập phân được coi là có nghĩa, vì vậy chúng ta giữ lại chúng:

>87.0g = `8.70e1`
>87.000g = `8.7000e1`

Đối với các số không có dấu thập phân, theo mặc định, các số 0 ở cuối được coi là không có nghĩa. Với số 2100 (không có thông tin bổ sung), chúng ta giả định rằng các số 0 ở cuối không có nghĩa, vì vậy chúng ta loại bỏ chúng:
>2100 = `2.1e3` (số 0 ở cuối được cho là không có nghĩa)

Tuy nhiên, nếu biết rằng số này được đo chính xác (hoặc số thực tế nằm giữa 2099.5 và 2100.5), thì chúng ta nên coi các số 0 đó là có nghĩa:
>2100 = `2.100e3` (số 0 ở cuối được biết là có nghĩa)

>**Mẹo:**<br>
>Thỉnh thoảng bạn có thể thấy một số được viết với dấu thập phân có các số 0 ở cuối. Đây là dấu hiệu cho biết các số đó có nghĩa.
>- 2100 = `2.100e3` (số 0 ở cuối được biết là có nghĩa)

Một trong những điều tuyệt vời về ký hiệu khoa học là nó luôn làm rõ có bao nhiêu chữ số có nghĩa.

Về mặt kỹ thuật, các số 87.0 và 87.000 có cùng giá trị (và cùng kiểu). Khi C++ lưu trữ bất kỳ số nào trong số này trong bộ nhớ, nó sẽ chỉ lưu trữ giá trị `87`. Và một khi được lưu trữ, không có cách nào để xác định từ giá trị được lưu trữ xem số nào trong hai số được nhập ban đầu.

Bây giờ chúng ta đã tìm hiểu về ký hiệu khoa học, chúng ta đã sẵn sàng để tìm hiểu về các số thực.

### **Bài Tập**

#### **Câu hỏi #1**

Chuyển đổi các số sau sang ký hiệu khoa học (sử dụng ký tự e để biểu diễn số mũ) và xác định xem mỗi số có bao nhiêu chữ số có nghĩa.
Nhớ giữ lại các số 0 ở cuối sau dấu thập phân, loại bỏ các số 0 ở cuối nếu không có dấu thập phân.

**a)** 34.50. 

<details>
<summary><b>Xem đáp án</b></summary>
    
`3.450e1` (4 chữ số có nghĩa)
</details>

**b)** 0.004000
<details>
<summary><b>Xem đáp án</b></summary>

`4.000e-3` (4 chữ số có nghĩa)
</details>

**c)** 123.005
<details>
<summary><b>Xem đáp án</b></summary>

`1.23005e2` (6 chữ số có nghĩa)
</details>

**d)** 146000
<details>
<summary><b>Xem đáp án</b></summary>

`1.46e5` (3 chữ số có nghĩa). Lưu ý, theo mặc định, các số 0 ở cuối trong một số nguyên không có dấu thập phân được coi là không có nghĩa.
</details>

**e)** 146000.001
<details>
<summary><b>Xem đáp án</b></summary>

`1.46000001e5` (9 chữ số có nghĩa)
</details>

**f)** 0.0000000008
<details>
<summary><b>Xem đáp án</b></summary>

`8e-10` (1 chữ số có nghĩa). Thừa số chính xác là 8 (có 1 chữ số có nghĩa), không phải 8.0 (có 2 chữ số có nghĩa).
</details>

**g)** 34500.0
<details>
<summary><b>Xem đáp án</b></summary>

`3.45000e4` (6 chữ số có nghĩa). Chúng ta không loại bỏ các số 0 ở cuối ở đây vì số này có dấu thập phân. Mặc dù dấu thập phân không ảnh hưởng đến giá trị của số, nó ảnh hưởng đến độ chính xác, do đó cần được tính vào các chữ số có nghĩa. Nếu số được ghi là 34500, thì đáp án sẽ là 3.45e4 (3 chữ số có nghĩa).
</details>

**h)** 146000 (giả sử biết các số 0 có nghĩa)
<details>
<summary><b>Xem đáp án</b></summary>

`1.46000e5` (6 chữ số có nghĩa)
</details>

## **Bài 4.8: <u>Số thực dấu phẩy động (Floating Point Numbers)</u>**

Số nguyên là lựa chọn tuyệt vời để đếm các số nguyên, nhưng đôi khi chúng ta cần lưu trữ những con số rất lớn (dương hoặc âm), hoặc những con số có phần thập phân. **Biến kiểu số thực (floating point)** là biến có thể lưu trữ một số có phần thập phân, ví dụ như `4320.0`, `-3.33` hoặc `0.01226`. Từ *"floating"* trong tên *"floating point"* ám chỉ việc dấu thập phân có thể "di chuyển" - nghĩa là nó có thể hỗ trợ một số lượng chữ số thay đổi trước và sau dấu thập phân.

>**Mẹo:**<br>
>Khi viết số thực trong code, dấu phân cách thập phân phải là dấu chấm (`.`). Nếu bạn đến từ quốc gia sử dụng dấu phẩy thập phân, bạn sẽ cần làm quen với việc sử dụng dấu chấm thay thế.

Có ba kiểu dữ liệu số thực phổ biến: `float`, `double` và `long double`. Giống như số nguyên, C++ không xác định kích thước cụ thể của các kiểu này (nhưng đảm bảo kích thước tối thiểu).

Trên các kiến trúc hiện đại, cách biểu diễn số thực gần như luôn tuân theo định dạng nhị phân **IEEE 754** (do William Kahan tạo ra). Trong định dạng này, một `float` chiếm 4 byte, một `double` chiếm 8 byte và một `long double` có thể tương đương với một double (8 byte), 80-bit (thường được làm tròn thành 12 byte) hoặc 16 byte.

Kiểu dữ liệu số thực luôn có dấu (có thể chứa các giá trị dương và âm).

|       Loại      | Kích thước tối thiểu | Kích thước điển hình |
|:---------------:|:--------------------:|:--------------------:|
| `float`         | 4 byte               | 4 byte               |
| `double`        | 8 byte               | 8 byte               |
| `long double`   | 8 byte               | 8, 12 hoặc 16 byte   |

Dưới đây là một số ví dụ về định nghĩa biến số thực:
>```
>float fValue;
>double dValue;
>long double ldValue;
>```

Khi sử dụng hằng số thực (floating point literals), hãy luôn bao gồm ít nhất một chữ số thập phân (ngay cả khi số thập phân là 0). Điều này giúp trình biên dịch hiểu rằng số đó là số thực chứ không phải số nguyên.

>```
>int x {5};      // 5 là số nguyên
>double y {5.0}; // 5.0 là số thực (không có hậu tố mặc định là kiểu double)
>float z {5.0f}; // 5.0 là số thực, hậu tố f nghĩa là kiểu float
>```

Lưu ý rằng theo mặc định, số thực mặc định là kiểu `double`. Hậu tố `f` được sử dụng để biểu thị một số thực kiểu `float`.

>**Thực hành tốt nhất**<br>
>Luôn đảm bảo kiểu của số thực bạn sử dụng khớp với kiểu của biến được gán hoặc dùng để khởi tạo. Nếu không, việc chuyển đổi không cần thiết sẽ xảy ra, có thể dẫn đến mất độ chính xác.

### **In ra số thực (Floating Point Numbers)**

**Xét chương trình đơn giản sau:**
>```
>#include <iostream>
>
>int main() {
>  std::cout << 5.0 << '\n';
>  std::cout << 6.7f << '\n';
>  std::cout << 9876543.21 << '\n';
>
>  return 0;
>}
>```

Kết quả của chương trình đơn giản này có thể khiến bạn ngạc nhiên:
>```
>5
>6.7
>9.87654e+06
>```


Trong trường hợp đầu tiên, `std::cout` in ra `5`, mặc dù chúng ta đã nhập `5.0`. Theo mặc định, `std::cout` sẽ không in ra phần thập phân của một số nếu phần thập phân đó bằng 0.

Trong trường hợp thứ hai, số được in ra như mong đợi.

Trong trường hợp thứ ba, nó được in ra ở dạng ký hiệu khoa học (nếu bạn cần ôn lại về dạng ký hiệu khoa học, hãy xem bài học [**4.7:
Giới thiệu về ký hiệu khoa học**](lesson4_7.ipynb).

### **Phạm vi của số thực dấu phẩy động**

Giả sử sử dụng biểu diễn IEEE 754:

| Kích thước                              | Giới hạn                                                                     | Độ chính xác |
|-----------------------------------------|------------------------------------------------------------------------------|--------------|
| 4 byte                                  | ±1.18 x 10<sup>-38</sup> đến ±3.4 x 10<sup>38</sup> and 0.0                  | 6-9 chữ số có nghĩa, thường là 7         | 
| 8 byte                                  | ±2.23 x 10<sup>-308</sup> đến ±1.80 x 10<sup>308</sup> và 0.0                | 15-18 chữ số có nghĩa, thường là 16     |
| 80-bit (thường sử dụng 12 hoặc 16 byte) | ±3.36 x 10<sup>-4932</sup> đến ±1.18 x 10<sup>4932</sup> và 0.0              | 18-21 chữ số có nghĩa                   |
| 16 byte                                 | ±3.36 x 10<sup>-4932</sup> đến ±1.18 x 10<sup>4932</sup> và 0.0              | 33-36 chữ số có nghĩa                   |

Kiểu số thực 80-bit là một ngoại lệ lịch sử. Trên các bộ xử lý hiện đại, nó thường được triển khai bằng cách sử dụng 12 hoặc 16 byte (đây là kích thước tự nhiên hơn để bộ xử lý xử lý).

Có vẻ hơi lạ khi kiểu số thực 80-bit có cùng phạm vi với kiểu số thực 16 byte. Điều này là do chúng có cùng số bit dành cho số mũ - tuy nhiên, số 16 byte có thể lưu trữ nhiều chữ số có nghĩa hơn.

### **Độ chính xác của số thực (Floating Point Precision)**

Hãy xét phân số 1/3. Biểu diễn thập phân của số này là 0.33333333333333... với các chữ số 3 lặp lại vô hạn. Nếu bạn viết con số này ra giấy, đến một lúc nào đó tay bạn sẽ mỏi và cuối cùng bạn sẽ dừng lại. Và con số bạn có được sẽ gần với 0.3333333333... (với các chữ số 3 lặp lại vô hạn) nhưng không chính xác tuyệt đối.

Trên máy tính, một số có độ chính xác vô hạn sẽ yêu cầu bộ nhớ vô hạn để lưu trữ, và chúng ta thường chỉ có 4 hoặc 8 byte cho mỗi giá trị. Bộ nhớ hạn chế này có nghĩa là số thực chỉ có thể lưu trữ một số lượng chữ số có nghĩa nhất định - bất kỳ chữ số có nghĩa bổ sung nào cũng bị mất hoặc được biểu diễn không chính xác. Số thực được lưu trữ thực sự sẽ gần với số mong muốn, nhưng không chính xác. Chúng tôi sẽ cung cấp một ví dụ về điều này trong phần tiếp theo.

**Độ chính xác** của một kiểu số thực xác định số chữ số có nghĩa mà nó có thể biểu diễn mà không mất thông tin.

Số chữ số có nghĩa của một kiểu số thực phụ thuộc vào cả kích thước (`float` có độ chính xác thấp hơn `double`) và giá trị cụ thể được lưu trữ (một số giá trị có thể được biểu diễn chính xác hơn những giá trị khác).

Ví dụ, một số kiểu `float` có độ chính xác từ 6 đến 9 chữ số. Điều này có nghĩa là `float` có thể biểu diễn chính xác bất kỳ số nào có tới 6 chữ số có nghĩa. Một số có 7 đến 9 chữ số có nghĩa có thể được biểu diễn chính xác hay không tùy thuộc vào giá trị cụ thể. Và một số có độ chính xác hơn 9 chữ số chắc chắn sẽ không được biểu diễn chính xác.

`double` có độ chính xác từ 15 đến 18 chữ số, với hầu hết các giá trị double có ít nhất 16 chữ số có nghĩa. `long double` có độ chính xác tối thiểu là 15, 18 hoặc 33 chữ số có nghĩa tùy thuộc vào số byte nó chiếm dụng.

>**Lưu ý quan trọng**<br>
>Một kiểu số thực chỉ có thể biểu diễn chính xác một số lượng nhất định các chữ số có nghĩa. Sử dụng một giá trị có nhiều chữ số có nghĩa hơn mức tối thiểu có thể dẫn đến việc giá trị được lưu trữ không chính xác.

### **Xuất số thực ra màn hình**

Khi xuất số thực, `std::cout` có độ chính xác mặc định là 6 - nghĩa là nó giả định tất cả các biến số thực chỉ có ý nghĩa đến 6 chữ số (độ chính xác tối thiểu của một `float`), và do đó nó sẽ cắt bỏ bất kỳ thứ gì sau đó.

Chương trình sau đây cho thấy `std::cout` cắt thành 6 chữ số:
>```
>#include <iostream>
>
>int main() {
>  std::cout << 9.87654321f << '\n';
>  std::cout << 987.654321f << '\n';
>  std::cout << 987654.321f << '\n';
>  std::cout << 9876543.21f << '\n';
>  std::cout << 0.0000987654321f << '\n';
>
>  return 0;
>}
>```

Chương trình này xuất ra:
>```
>9.87654
>987.654
>987654
>9.87654e+006
>9.87654e-005
>```

Lưu ý rằng mỗi số này chỉ có 6 chữ số có nghĩa.

Ngoài ra, lưu ý rằng `std::cout` sẽ chuyển sang xuất số theo ký hiệu khoa học trong một số trường hợp. Tùy thuộc vào trình biên dịch, số mũ thường được lấp đầy với một số chữ số tối thiểu. Đừng lo lắng, `9.87654e+006` giống với `9.87654e6`, chỉ khác là có thêm một vài số mũ 0. Số lượng tối thiểu chữ số mũ được hiển thị phụ thuộc vào trình biên dịch (Visual Studio sử dụng 3, một số trình biên dịch khác sử dụng 2 theo tiêu chuẩn C99).

Chúng ta có thể ghi đè lên độ chính xác mặc định mà `std::cout` hiển thị bằng cách sử dụng **hàm thao tác xuất** có tên `std::setprecision()`. Hàm thao tác xuất thay đổi cách dữ liệu được xuất ra và được định nghĩa trong header `<iomanip>`.

>```
>#include <iomanip> // for output manipulator std::setprecision()
>#include <iostream>
>
>int main() {
>  std::cout << std::setprecision(17); // hiển thị 17 chữ số thập phân
>  std::cout << 3.33333333333333333333333333333333333333f << '\n'; // hậu tố f nghĩa là float
>  std::cout << 3.33333333333333333333333333333333333333 << '\n'; // không có hậu tố nghĩa là double
>
>  return 0;
>}
>```

**Xuất ra:**
>```
>3.3333332538604736
>3.3333333333333335
>```

Bởi vì chúng tôi đặt độ chính xác thành 17 chữ số có nghĩa trong hàm `std::setprecision()`, mỗi số ở trên được in với 17 chữ số. Nhưng, như bạn có thể thấy, các số chắc chắn không chính xác đến 17 chữ số! Và vì `float` kém chính xác hơn `double` nên `float` có nhiều lỗi hơn.

>**Mẹo**<br>
>Hàm thao tác xuất (và hàm thao tác nhập) có tính **dính**. Nghĩa là nếu bạn đặt giá trị cho chúng, giá trị đó sẽ được giữ nguyên cho các lần in/nhập tiếp theo.\
>Ngoại lệ duy nhất là hàm `std::setw`. Một số hoạt động IO có thể đặt lại `std::setw`, vì vậy ta nên sử dụng `std::setw` mỗi khi cần thiết.

Vấn đề về độ chính xác không chỉ ảnh hưởng đến các số thập phân mà còn ảnh hưởng đến bất kỳ số nào có quá nhiều chữ số có nghĩa. Hãy xem xét một số lớn:

>```
>#include <iomanip> // for std::setprecision()
>#include <iostream>
>
>int main() {
>  float f { 123456789.0f }; // f có 10 chữ số có nghĩa
>  std::cout << std::setprecision(9); // để hiển thị 9 chữ số trong f
>  std::cout << f << '\n';
>
>  return 0;
>}
>```

Kết quả in ra:
>`123456792`

Số `123456792` lớn hơn `123456789`. Giá trị `123456789.0` có 10 chữ số có nghĩa, nhưng các giá trị `float` thường chỉ có độ chính xác khoảng `7` chữ số (và kết quả `123456792` chỉ chính xác đến 7 chữ số có nghĩa). Điều này có nghĩa là chúng ta đã mất một phần độ chính xác! Khi mất độ chính xác vì không thể lưu trữ số chính xác, đây được gọi là **lỗi làm tròn (rounding error)**.

Do đó, cần thận trọng khi sử dụng số thực yêu cầu độ chính xác cao hơn khả năng lưu trữ của biến.

>**Thực hành tốt nhất**<br>
>Ưu tiên sử dụng `double` hơn `float` trừ khi dung lượng là hạn chế, vì thiếu độ chính xác trong `float` thường dẫn đến sai số.



### **Các lỗi làm tròn khiến việc so sánh số thực trở nên khó khăn`**

Số thực phức tạp để làm việc do những khác biệt không dễ thấy giữa số nhị phân (cách lưu trữ dữ liệu) và số thập phân (cách chúng ta suy nghĩ) về một giá trị. Xét phân số 1/10. Trong hệ thập phân, nó được biểu diễn dễ dàng dưới dạng 0.1, và chúng ta thường coi 0.1 là một số dễ biểu diễn với 1 chữ số có nghĩa. Tuy nhiên, trong hệ nhị phân, giá trị thập phân 0.1 được biểu diễn bởi chuỗi vô hạn: `0.00011001100110011…` Do đó, khi gán 0.1 cho một số thực, chúng ta sẽ gặp phải các vấn đề về độ chính xác.
>```
>#include <iomanip> // for std::setprecision()
>#include <iostream>
>
>int main()
>{
>    double d {0.1};
>    std::cout << d << '\n'; // sử dụng độ chính xác mặc định của cout là 6
>    std::cout << std::setprecision(17);
>    std::cout << d << '\n';
>
>    return 0;
>}
>```

**Kết quả in ra:**
>```
>0.1
>0.10000000000000001
>```

Ở dòng đầu tiên, `std::cout` in ra `0.1`, như mong đợi.

Ở dòng dưới cùng, nơi chúng ta yêu cầu `std::cout` hiển thị 17 chữ số thập phân, chúng ta thấy rằng `d` thực ra không hoàn toàn bằng `0.1`! Điều này là do kiểu `double` phải cắt bớt giá trị xấp xỉ do bộ nhớ của nó bị hạn chế. Kết quả là một số chính xác đến 16 chữ số có nghĩa (đó là đảm bảo của kiểu `double`), nhưng số đó không chính xác bằng `0.1`. Lỗi làm tròn có thể khiến một số nhỏ hơn hoặc lớn hơn một chút, tùy thuộc vào vị trí xảy ra việc cắt bỏ giá trị.

Lỗi làm tròn có thể dẫn đến những hậu quả không mong đợi:
>```
>#include <iomanip> // for std::setprecision()
>#include <iostream>
>
>int main()
>{
>    std::cout << std::setprecision(17);
>
>    double d1 { 1.0 };
>    std::cout << d1 << '\n';
>
>    double d2 { 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // đáng ra phải bằng 1.0
>    std::cout << d2 << '\n';
>
>    return 0;
>}
>```

>```
>1
>0.99999999999999989
>```

Mặc dù chúng ta có thể mong đợi `d1` và `d2` bằng nhau, nhưng chúng ta thấy rằng chúng không bằng nhau. Nếu chúng ta so sánh `d1` và `d2` trong chương trình, chương trình có thể sẽ không hoạt động như mong đợi. Do số thực thường không chính xác, việc so sánh số thực nói chung là một vấn đề rắc rối - chúng tôi sẽ thảo luận thêm về chủ đề này (và các giải pháp) trong bài **6.6 - Các toán tử quan hệ và so sánh số thực**.

Một lưu ý cuối cùng về lỗi làm tròn: các phép toán (như cộng và nhân) có xu hướng khiến lỗi làm tròn tăng lên. Vì vậy, mặc dù `0.1` có lỗi làm tròn ở chữ số thập phân thứ 17, nhưng khi chúng ta cộng `0.1` mười lần, lỗi làm tròn đã lan sang chữ số thập phân thứ 16. Các phép toán tiếp tục sẽ khiến lỗi này trở nên đáng kể hơn.

>**Lưu ý quan trọng:**<br>
>Lỗi làm tròn xảy ra khi không thể lưu trữ chính xác một số. Điều này có thể xảy ra ngay cả với những số đơn giản, như 0.1. Do đó, lỗi làm tròn có thể, và thực sự, xảy ra mọi lúc. Lỗi làm tròn không phải là ngoại lệ - chúng là quy tắc. Không bao giờ giả định số thực của bạn là chính xác tuyệt đối.
>
>Một hệ quả phụ của quy tắc này là: hãy cẩn thận khi số dấu phẩy động cho dữ liệu tài chính hoặc tiền tệ.

>**Nội dung liên quan**<br>
>Để hiểu rõ hơn về cách các số dấu phẩy động được lưu trữ ở dạng nhị phân, hãy xem công cụ [float.expose](https://float.exposed/0x3dcccccd).
>
>Để tìm hiểu thêm về số dấu phẩy động và lỗi làm tròn, [floating-point-gui.de](https://floating-point-gui.de/) và [fabiensanglard.net](https://fabiensanglard.net/floating_point_visually_explained/index.html) có các hướng dẫn dễ tiếp cận về chủ đề này.



### **`NaN` và `Inf` (Not a Number và Infinity)**

Có hai loại đặc biệt của số thực:
- `Inf` (Infinity): Biểu diễn vô cực, có thể là dương hoặc âm.
- `NaN` (Not a Number): Không phải là một số. Có nhiều loại `NaN` khác nhau (chúng tôi sẽ không đề cập ở đây).

`NaN` và `Inf` chỉ khả dụng nếu trình biên dịch sử dụng một định dạng cụ thể (IEEE 754) cho số thực. Nếu sử dụng định dạng khác, đoạn mã sau sẽ tạo ra hành vi bất định.

Đây là một chương trình hiển thị cả ba loại số:
>```
>#include <iostream>
>
>int main()
>{
>    double zero {0.0};
>    double posinf { 5.0 / zero }; // vô cực dương
>    std::cout << posinf << '\n';
>
>    double neginf { -5.0 / zero }; // vô cực âm
>    std::cout << neginf << '\n';
>
>    double nan { zero / zero }; // không phải là một số (không hợp lý về mặt toán học)
>    std::cout << nan << '\n';
>
>    return 0;
>}
>```

Kết quả chạy trên Visual Studio 2008 trên Windows:
>```
>1.#INF
>-1.#INF
>1.#IND
>```

`INF` là viết tắt của vô cực (infinity), và `IND` là viết tắt của không xác định (indeterminate). Lưu ý rằng kết quả của việc in ra `Inf` và `NaN` phụ thuộc vào nền tảng, vì vậy kết quả của bạn có thể khác nhau.

>**Thực hành tốt nhất**<br>
>Tốt nhất là nên tránh chia cho `0.0` hoàn toàn, ngay cả khi trình biên dịch của bạn hỗ trợ.

### **Kết luận**

Tóm lại, có hai điều bạn cần nhớ về số thực:
- Số thực hữu ích để lưu trữ các số rất lớn hoặc rất nhỏ, bao gồm cả các số có phần thập phân.
- Số thực thường có các lỗi làm tròn nhỏ, ngay cả khi số đó có ít chữ số có nghĩa hơn độ chính xác. Trong nhiều trường hợp, chúng ta không chú ý đến những lỗi này vì chúng rất nhỏ và vì các số được cắt bớt để hiển thị. Tuy nhiên, việc so sánh các số thực có thể không mang lại kết quả mong đợi. Thực hiện các phép toán trên các giá trị này sẽ khiến lỗi làm tròn tăng lên.

## **Bài 4.9: <u>Giá trị logic (Boolean Values)</u>**

Trong thực tế, chúng ta thường xuyên đặt ra hoặc được hỏi những câu hỏi chỉ có thể trả lời bằng "có" hoặc "không". Ví dụ: "Táo có phải là trái cây?" (Có) hoặc "Bạn có thích măng tây không?" (Không).

Tương tự, ta có thể đặt ra những câu hỏi có thể trả lời bằng "đúng" hoặc "sai". Ví dụ: "Táo là một loại trái cây" (Đúng) hoặc "Tôi thích măng tây" (Sai).

Những loại câu chỉ có hai kết quả khả thi này (có/đúng hoặc không/sai) rất phổ biến, do đó nhiều ngôn ngữ lập trình bao gồm một kiểu dữ liệu đặc biệt để xử lý chúng. Kiểu dữ liệu này được gọi là **Boolean** (Lưu ý: **Boolean** được viết hoa vì nó được đặt theo tên của nhà phát minh ra nó, George Boole).

### **Biến Boolean**

**Biến Boolean** là biến chỉ có thể có hai giá trị: `true` (đúng) và `false` (sai).

Để khai báo một biến Boolean, chúng ta sử dụng từ khóa `bool`.
>`bool b;`

Để khởi tạo hoặc gán giá trị `true` hoặc `false` cho một biến Boolean, chúng ta sử dụng các từ khóa `true` và `false`.
>```
>bool b1 { true };
>bool b2 { false };
>b1 = false;
>bool b3 {}; // mặc định khởi tạo thành false
>```

Giống như toán tử một ngôi "trừ" (`-`) có thể được sử dụng để tạo ra một số nguyên âm, toán tử logic **NOT** (`!`) có thể được sử dụng để đảo ngược giá trị Boolean từ `true` thành `false` hoặc `false` thành `true`:
>```
>bool b1 { !true }; // b1 sẽ được khởi tạo với giá trị false
>bool b2 { !false }; // b2 sẽ được khởi tạo với giá trị true
>```

Giá trị Boolean không thực sự được lưu trữ trong các biến Boolean dưới dạng các từ `"true"` hoặc `"false"`. Thay vào đó, chúng được lưu trữ dưới dạng số nguyên: `true` trở thành số nguyên `1`, và `false` trở thành số nguyên `0`. Tương tự, khi các giá trị Boolean được đánh giá, chúng không thực sự được đánh giá thành `"true"` hoặc `"false"`. Chúng được đánh giá thành các số nguyên `0` (sai) hoặc `1` (đúng). 

Vì Boolean thực sự lưu trữ các số nguyên, nên chúng được coi là một **kiểu dữ liệu giống số nguyên (integral type)**.

### **In giá trị Boolean**

Khi chúng ta in các giá trị Boolean, `std::cout` sẽ in `0` cho `false` và `1` cho `true`:
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << true << '\n'; // true được đánh giá thành 1
>    std::cout << !true << '\n'; // !true được đánh giá thành 0
>
>    bool b {false};
>    std::cout << b << '\n'; // b là false, được đánh giá thành 0
>    std::cout << !b << '\n'; // !b là true, được đánh giá thành 1
>    return 0;
>}
>```

**Kết quả in:**
>```
>1
>0
>0
>1
>```

Nếu bạn muốn `std::cout` in `"true"` hoặc `"false"` thay vì `0` hoặc `1`, bạn có thể sử dụng `std::boolalpha`. 

**Đây là một ví dụ:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << true << '\n';
>    std::cout << false << '\n';
>
>    std::cout << std::boolalpha; // in bool dưới dạng true hoặc false
>
>    std::cout << true << '\n';
>    std::cout << false << '\n';
>    return 0;
>}
>```

**Kết quả in:**
>```
>1
>0
>true
>false
>```

Bạn có thể sử dụng `std::noboolalpha` để tắt tính năng in `"true"` hoặc `"false"`.

### **Chuyển đổi từ số nguyên sang Boolean**

Khi sử dụng khởi tạo chuẩn (uniform initialization), bạn có thể khởi tạo biến bằng các giá trị số nguyên `0` (cho `false`) và `1` (cho `true`) (nhưng thực sự nên sử dụng `false` và `true` thay thế). Các giá trị số nguyên khác sẽ gây ra lỗi biên dịch:
>```
>#include <iostream>
>
>int main()
>{
>	bool bFalse { 0 }; // okay: khởi tạo thành false
>	bool bTrue  { 1 }; // okay: khởi tạo thành true
>	bool bNo    { 2 }; // error: không được phép chuyển đổi thu hẹp kiểu dữ liệu
>
>	std::cout << bFalse << bTrue << bNo << '\n';
>
>	return 0;
>}
>```

Tuy nhiên, trong bất kỳ ngữ cảnh khai báo nào cho phép chuyển đổi số nguyên sang Boolean, số nguyên `0` sẽ được chuyển đổi thành `false`, và bất kỳ số nguyên nào khác sẽ được chuyển đổi thành `true`.
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << std::boolalpha; // in bool dưới dạng true hoặc false
>	
>    bool b1 = 4 ; // khởi tạo sao chép cho phép chuyển đổi ẩn từ int sang bool
>    std::cout << b1 << '\n';
>
>    bool b2 = 0 ; // khởi tạo sao chép cho phép chuyển đổi ẩn từ int sang bool
>    std::cout << b2 << '\n';
>    
>    return 0;
>}
>```

**Kết quả in ra:**
>```
>true
>false
>```

**Lưu ý:** `bool b1 = 4;` có thể tạo ra cảnh báo. Nếu vậy, bạn cần tắt tính năng `"treating warnings as errors"` (coi cảnh báo như lỗi) để biên dịch ví dụ.

### **Nhập giá trị Boolean**

Nhập giá trị Boolean bằng `std::cin` đôi khi gây khó khăn cho người lập trình mới.

Xem xét chương trình sau:
>```
>#include <iostream>
>
>int main()
>{
>    bool b{}; // mặc định khởi tạo thành false
>    std::cout << "Nhập một giá trị Boolean: ";
>    std::cin >> b;
>    std::cout << "Bạn đã nhập: " << b << '\n';
>    
>    return 0;
>}
>```

>```
>Nhập một giá trị Boolean: true
>Bạn đã nhập: 0
>```

Điều gì đã xảy ra vậy?

Lý do là `std::cin` chỉ chấp nhận hai đầu vào cho biến Boolean: `0` (sai) và `1` (đúng). Bất kỳ đầu vào nào khác sẽ khiến `std::cin` hoạt động không chính xác mà không báo lỗi. Trong trường hợp này, vì chúng ta nhập `"true"`, `std::cin` đã sai sót và gán giá trị `false` cho biến `b`. Do đó, khi `std::cout` in giá trị của `b`, nó hiển thị `0`.

Để cho phép `std::cin` chấp nhận `"false"` và `"true"` làm đầu vào, tùy chọn `std::boolalpha` phải được bật:
>```
>#include <iostream>
>
>int main()
>{
>    bool b{};
>    std::cout << "Nhập một giá trị Boolean: ";
>
>    // Cho phép người dùng nhập "true" hoặc "false" cho giá trị Boolean
>    // Phân biệt chữ hoa chữ thường, ví dụ: True hoặc TRUE sẽ không hoạt động
>    std::cin >> std::boolalpha;
>    std::cin >> b;
>
>    std::cout << "Bạn đã nhập: " << b << '\n';
>
>    return 0;
>}

>**Cảnh báo**<br>
>Khi bật `std::boolalpha`, `0` và `1` sẽ không còn được coi là đầu vào Boolean mà sẽ được chuyển đổi thành `"false"` (cùng với bất kỳ đầu vào nào khác ngoài `"true"`).\
>Bật `std::boolalpha` chỉ cho phép chấp nhận `"true"` và `"false"` viết thường. Các biến thể viết hoa sẽ không được chấp nhận.


### **Giá trị trả về Boolean (Boolean Return Values)**

Giá trị Boolean thường được sử dụng làm giá trị trả về cho các hàm kiểm tra xem một điều kiện nào đó là đúng hay sai. Các hàm này thường được đặt tên bắt đầu bằng từ **`is`** (ví dụ: `isEqual`) hoặc **`has`** (ví dụ: `hasCommonDivisor`).

**Xem xét ví dụ sau về hàm `isEqual`:**
>```
>#include <iostream>
>
>// Trả về true nếu x và y bằng nhau, ngược lại trả về false
>bool isEqual(int x, int y)
>{
>    return x == y; // toán tử == trả về true nếu x bằng y, ngược lại trả về false
>}
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x{};
>    std::cin >> x;
>
>    std::cout << "Nhập một số nguyên khác: ";
>    int y{};
>    std::cin >> y;
>
>    std::cout << std::boolalpha; // in bool dưới dạng true hoặc false
>
>    std::cout << x << " và " << y << " có bằng nhau không? ";
>    std::cout << isEqual(x, y) << '\n'; // sẽ trả về true hoặc false
>
>    return 0;
>}
>```

**Đây là kết quả chạy của chương trình:**
>```
>Nhập một số nguyên: 5
>Nhập một số nguyên khác: 5
>5 và 5 có bằng nhau không? true

>```
>Nhập một số nguyên: 6
>Nhập một số nguyên khác: 4
>6 và 4 có bằng nhau không? false
>```

**Giải thích hoạt động:**

Đầu tiên, chương trình đọc các giá trị số nguyên cho `x` và `y`. Tiếp theo, biểu thức `isEqual (x, y)` được tính toán. Trong lần chạy đầu tiên, điều này dẫn đến việc gọi hàm `isEqual(5, 5)`. Bên trong hàm đó, `5 == 5` được đánh giá, tạo ra giá trị `true`. Giá trị `true` được trả về cho trình gọi để được in bởi `std::cout`. Trong lần chạy thứ hai, lệnh gọi `isEqual(6, 4)` trả về giá trị `false`.

Mặc dù ban đầu giá trị Boolean có thể hơi khó làm quen, nhưng một khi bạn hiểu được cách thức hoạt động của chúng, bạn sẽ thấy chúng đơn giản và hữu ích! Giá trị Boolean đóng vai trò quan trọng trong ngôn ngữ lập trình C++, và bạn sẽ sử dụng chúng nhiều hơn tất cả các kiểu dữ liệu cơ bản khác cộng lại!

## **Bài 4.10: <u>Giới thiệu về câu lệnh `if`</u>**

Hãy tưởng tượng bạn đang đi chợ và bạn cùng phòng nói với bạn, *"nếu họ có bán dâu tây giảm giá, hãy mua một ít"*. Đây là một câu lệnh điều kiện, nghĩa là bạn chỉ thực hiện một hành động *("mua một ít")* khi điều kiện *("họ có bán dâu tây giảm giá")* là đúng.

Những câu lệnh điều kiện như vậy rất phổ biến trong lập trình, vì chúng cho phép chúng ta triển khai hành vi theo điều kiện vào các chương trình của mình. Loại câu lệnh điều kiện đơn giản nhất trong C++ được gọi là câu lệnh `if`. Câu lệnh `if` cho phép chúng ta chỉ thực thi một (hoặc nhiều) dòng lệnh nếu một điều kiện nào đó là đúng.

**Cấu trúc đơn giản nhất của câu lệnh `if` như sau:**
>```
>if (condition) true_statement;
>```

Để dễ đọc, cấu trúc này thường được viết thành:
>```
>if (condition)
>    true_statement;
>```

**Điều kiện** (còn được gọi là **biểu thức điều kiện**) là một biểu thức được đánh giá thành giá trị Boolean (`true` hoặc `false`).

Nếu điều kiện của câu lệnh `if` được đánh giá thành giá trị Boolean `true`, thì `true_statement` được thực thi. Ngược lại, nếu điều kiện được đánh giá thành giá trị Boolean `false`, thì `true_statement` sẽ bị bỏ qua.



### **Ví dụ về chương trình sử dụng câu lệnh `if`**

**Xét chương trình sau:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    if (x == 0)
>        std::cout << "Giá trị bằng 0\n";
>
>    return 0;
>}
>```


**Đây là kết quả chạy của chương trình:**
>```
>Nhập một số nguyên: 0
>Giá trị bằng 0
>```

Chúng ta hãy xem xét chi tiết cách hoạt động của chương trình này.

Đầu tiên, người dùng nhập một số nguyên. Sau đó, điều kiện `x == 0` được đánh giá. Toán tử so sánh bằng (`==`) được sử dụng để kiểm tra xem hai giá trị có bằng nhau hay không. Toán tử `==` trả về `true` nếu các toán hạng bằng nhau và `false` nếu chúng không bằng nhau. Vì `x` có giá trị `0` và `0 == 0` là `true`, biểu thức này được đánh giá thành `true`.

Do điều kiện được đánh giá thành `true`, câu lệnh tiếp theo được thực thi, in ra `"Giá trị bằng 0"`.

Đây là một lần chạy khác của chương trình này:
>```
>Nhập một số nguyên: 5
>```

Trong trường hợp này, `x == 0` được đánh giá thành `false`. Câu lệnh tiếp theo bị bỏ qua, chương trình kết thúc và không in thêm gì nữa.

>**Cảnh báo**<br>
>Câu lệnh `if` chỉ có thể thực thi có điều kiện một câu lệnh duy nhất. Chúng ta sẽ thảo luận về cách thực thi có điều kiện nhiều câu lệnh trong bài học 8.2 - Câu lệnh if và khối lệnh (If statements and blocks).

### **Câu lệnh `if-else`**

Trong ví dụ trên, nếu chúng ta muốn thông báo cho người dùng rằng số họ nhập vào khác `0` thì sao?

**Chúng ta có thể viết như thế này:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    if (x == 0)
>        std::cout << "Giá trị bằng 0\n";
>    if (x != 0)
>        std::cout << "Giá trị khác 0\n";
>
>    return 0;
>}
>```

**Hoặc như thế này:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    bool zero { (x == 0) };
>    if (zero)
>        std::cout << "Giá trị bằng 0\n";
>    if (!zero)
>        std::cout << "Giá trị khác 0\n";
>
>    return 0;
>}
>```

Cả hai chương trình này đều phức tạp hơn mức cần thiết. Thay vào đó, chúng ta có thể sử dụng một dạng khác của câu lệnh `if` được gọi là `if-else`. Cấu trúc của `if-else` như sau:
>```
>if (condition)
>    true_statement;
>else
>    false_statement;
>```

Nếu điều kiện được đánh giá thành giá trị Boolean `true`, thì `true_statement` được thực thi. Ngược lại, `false_statement` sẽ được thực thi.

**Hãy sửa đổi chương trình trước đó của chúng ta để sử dụng `if-else`:**
>```
>#include <iostream>
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    if (x == 0)
>        std::cout << "Giá trị bằng 0\n";
>    else
>        std::cout << "Giá trị khác 0\n";
>
>    return 0;
>}
>```

**Bây giờ chương trình của chúng ta sẽ tạo ra đầu ra sau:**
>```
>Nhập một số nguyên: 0
>Giá trị bằng 0
>Nhập một số nguyên: 5
>Giá trị khác 0
>```

### **Nối tiếp các câu lệnh `if` (chaining `if` statements)**

Trong lập trình, đôi khi chúng ta cần kiểm tra nhiều điều kiện theo thứ tự. Để thực hiện điều này, chúng ta có thể sử dụng các câu lệnh `if` (hoặc `if-else`) nối tiếp nhau.

**Ví dụ:**
>```
>#include <iostream>
>
>int main() {
>  std::cout << "Nhập một số nguyên: ";
>  int x;
>  std::cin >> x;
>
>  if (x > 0) {
>    std::cout << "Giá trị dương\n";
>  } else if (x < 0) {
>    std::cout << "Giá trị âm\n";
>  } else {
>    std::cout << "Giá trị bằng 0\n";
>  }
>
>  return 0;
>}
>```

**Đây là kết quả chạy của chương trình trong một vài trường hợp:**
>```
>Nhập một số nguyên: 4
>Giá trị dương
>```

>```
>Nhập một số nguyên: -3
>Giá trị âm
>```

>```
>Nhập một số nguyên: 0
>Giá trị bằng 0
>```

**Giải thích:**

Toán tử so sánh `<` được dùng để kiểm tra xem một giá trị có nhỏ hơn giá trị khác hay không. Tương tự, toán tử so sánh `>` dùng để kiểm tra xem một giá trị có lớn hơn giá trị khác hay không. Cả hai toán tử này đều trả về giá trị **Boolean** (`true` hoặc `false`).
Chương trình có thể in ra nhiều kết quả khác nhau phụ thuộc vào điều kiện được đáp ứng.



**Lưu ý:** Bạn có thể nối tiếp các câu lệnh `if` nhiều lần tùy thuộc vào số điều kiện cần kiểm tra. Cách sử dụng này sẽ được minh họa rõ hơn trong phần bài tập ở cuối bài.


### **Giá trị trả về Boolean và câu lệnh `if`**

Trong bài học trước ([**4.9 - Giá trị logic**](lesson4_9.ipynb)), chúng ta đã viết một chương trình sử dụng hàm để trả về giá trị Boolean:
>```
>#include <iostream>
>
>// Kiểm tra xem x và y có bằng nhau không (true nếu bằng, false nếu khác)
>bool isEqual(int x, int y)
>{
>    return x == y; // Toán tử == trả về true nếu x bằng y, và false nếu khác
>}
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    std::cout << "Nhập một số nguyên khác: ";
>    int y {};
>    std::cin >> y;
>
>    std::cout << std::boolalpha; // In giá trị Boolean dưới dạng true hoặc false
>
>    std::cout << x << " và " << y << " có bằng nhau không? ";
>    std::cout << isEqual(x, y); // Sẽ trả về true hoặc false
>
>    std::cout << '\n';
>
>    return 0;
>}
>```

Bây giờ, chúng ta hãy cải thiện chương trình này bằng cách sử dụng câu lệnh `if`:
>```
>#include <iostream>
>
>// Kiểm tra xem x và y có bằng nhau không (true nếu bằng, false nếu khác)
>bool isEqual(int x, int y)
>{
>    return x == y; // Toán tử == trả về true nếu x bằng y, và false nếu khác
>}
>
>int main()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int x {};
>    std::cin >> x;
>
>    std::cout << "Nhập một số nguyên khác: ";
>    int y {};
>    std::cin >> y;
>
>    if (isEqual(x, y))
>        std::cout << x << " và " << y << " bằng nhau\n";
>    else
>        std::cout << x << " và " << y << " không bằng nhau\n";
>
>    return 0;
>}
>```

**Giải thích:**
- Biểu thức điều kiện trong trường hợp này đơn giản là việc gọi hàm `isEqual`, vốn sẽ trả về một giá trị Boolean.
- Chương trình kiểm tra giá trị trả về của hàm `isEqual` bằng câu lệnh `if`.
    - Nếu `isEqual` trả về `true` (nghĩa là `x` và `y` bằng nhau), dòng lệnh trong khối `if` sẽ được thực thi.
    - Ngược lại, nếu `isEqual` trả về `false` (nghĩa là `x` và `y` khác nhau), dòng lệnh trong khối `else` sẽ được thực thi.

**Ưu điểm:**
- Sử dụng câu lệnh `if` với hàm trả về giá trị Boolean giúp code dễ đọc và dễ hiểu hơn.
- Tách biệt logic kiểm tra điều kiện ra thành một hàm riêng, giúp code có tính mô-đun hơn và dễ dàng tái sử dụng.

**Chạy thử:**
>```
>Nhập một số nguyên: 5
>Nhập một số nguyên khác: 5
>5 và 5 bằng nhau
>```

>```
>Nhập một số nguyên: 6
>Nhập một số nguyên khác: 4
>6 và 4 không bằng nhau
>```

**Lưu ý:** Bất kỳ hàm nào trả về giá trị Boolean đều có thể được sử dụng trong biểu thức điều kiện của câu lệnh `if`.

### **Điều kiện không phải Boolean (Non-Boolean conditionals)**

Trong các ví dụ trước đó, điều kiện của câu lệnh `if` đều là các giá trị Boolean (`true` hoặc `false`), biến Boolean hoặc hàm trả về giá trị Boolean. Nhưng điều gì xảy ra nếu điều kiện là một biểu thức không được tính toán thành giá trị Boolean?

**Sẽ có phép chuyển đổi ngầm**

Trong trường hợp này, biểu thức điều kiện sẽ được chuyển đổi ngầm sang giá trị Boolean. Các quy tắc chuyển đổi như sau:
- Giá trị khác `0` được chuyển thành `true`.
- Giá trị bằng `0` được chuyển thành `false`.

**Ví dụ:**
>```
>#include <iostream>
>
>int main() {
>  if (4) // Không hợp lý nhưng dùng để minh họa
>    std::cout << "hi\n";
>  else
>    std::cout << "bye\n";
>
>  return 0;
>}
>```

Kết quả chạy sẽ in ra `"hi"` vì `4` là giá trị khác `0` nên được chuyển đổi thành `true`, khiến câu lệnh trong khối `if` được thực thi.

**Lưu ý:**
- Mặc dù cú pháp cho phép điều kiện không phải Boolean, nhưng đây thường không phải là cách viết code tốt.
- Sử dụng các biểu thức trả về giá trị Boolean rõ ràng sẽ giúp code dễ đọc và dễ hiểu hơn.
- Tránh sử dụng các phép chuyển đổi ngầm này trừ khi bạn hiểu rõ tác dụng của chúng và chắc chắn rằng chúng sẽ không gây ra lỗi.

    **Sử dụng điều kiện Boolean rõ ràng**
    >```
    >#include <iostream>
    >
    >int main() {
    >  int x = 4;
    >  if (x != 0) // Điều kiện rõ ràng
    >    std::cout << "x khác 0\n";
    >  else
    >    std::cout << "x bằng 0\n";
    >
    >  return 0;
    >}
    >```

    Trong đoạn code này, điều kiện `x != 0` rõ ràng hơn so với việc dựa vào phép chuyển đổi ngầm.

### **Câu lệnh `if` và early return (If-statements and early returns)**

**Early Return là gì?**

Trong lập trình, **early return** (trả về sớm) là một câu lệnh `return` xuất hiện bên trong một hàm nhưng không phải là dòng lệnh cuối cùng. Khi gặp early return, hàm sẽ dừng thực thi và trả về giá trị cho bên hàm gọi (caller) ngay lập tức, thay vì thực hiện đến hết hàm như thông thường.

Ví dụ về early return không cần thiết:
>```
>void print() {
>  std::cout << "A" << '\n';
>
>  return; // Hàm luôn trả về cho bên gọi tại đây
>
>  std::cout << "B" << '\n'; // Dòng này không bao giờ được in ra
>}
>```

Trong ví dụ này, vì `return;` luôn được thực thi trước, dòng `std::cout << "B" << '\n';` sẽ không bao giờ được thực hiện. Do đó, thay vì dùng early return không cần thiết, chúng ta có thể loại bỏ dòng `std::cout << "B" << '\n';` và lúc này return không còn là early return nữa.

**Sử dụng early return kết hợp với câu lệnh `if`:**

Tuy nhiên, khi kết hợp với câu lệnh `if`, early return trở thành một cách hữu ích để kiểm soát giá trị trả về của hàm dựa trên điều kiện.
>```
>#include <iostream>
>
>// Tính giá trị tuyệt đối của x
>int abs(int x) {
>  if (x < 0)
>    return -x; // Early return (chỉ khi x < 0)
>
>  return x;
>}
>
>int main() {
>  std::cout << abs(4) << '\n'; // In ra 4
>  std::cout << abs(-3) << '\n'; // In ra 3
>
>  return 0;
>}
>```

Khi gọi `abs(4)`, giá trị của `x` là `4`. Điều kiện `if (x < 0)` sai nên early return không được thực thi. Hàm trả về giá trị `x` (bằng `4`) cho bên gọi ở cuối hàm.

Khi gọi `abs(-3)`, giá trị của `x` là `-3`. Điều kiện `if (x < 0)` đúng nên early return được thực thi. Hàm trả về `-x` (bằng `3`) cho bên gọi tại thời điểm này.

Trước đây, việc sử dụng **early return** thường không được khuyến khích. Tuy nhiên, trong lập trình hiện đại, **early return** được chấp nhận rộng rãi hơn, đặc biệt khi chúng giúp đơn giản hóa hàm hoặc dừng hàm sớm do lỗi.

>**Bài học liên quan:**<br>
>Bài 8.11 - Break và Continue sẽ thảo luận chi tiết hơn về tranh cãi liên quan đến early return.\
>Bài 8.2 - Câu Lệnh if và Khối Lệnh sẽ tiếp tục khám phá về các câu lệnh if.

### **Bài tập**

**Câu hỏi #1:** Early return (trả về sớm) là gì và hoạt động như thế nào?
<details>
<summary><b>Đáp án:</b></summary>

Early return là một câu lệnh `return` xuất hiện bên trong một hàm nhưng không phải là dòng lệnh cuối cùng. Khi gặp early return, hàm sẽ dừng thực thi và trả về giá trị cho hàm gọi (caller) ngay lập tức, thay vì thực hiện đến hết hàm như thông thường.
</details>

**Câu hỏi #2:** Số nguyên tố là một số tự nhiên lớn hơn 1 chỉ chia hết cho 1 và chính nó. Viết chương trình yêu cầu người dùng nhập một số từ 0 đến 9 (bao gồm cả 0 và 9). Nếu người dùng nhập một số nguyên tố (2, 3, 5 hoặc 7), hãy in ra "The digit is prime" (Số này là số nguyên tố). Ngược lại, hãy in ra "The digit is not prime" (Số này không phải số nguyên tố). 
<details>
<summary><b>Gợi ý:</b></summary>
  
Sử dụng chuỗi các câu lệnh `if-else` để so sánh số người dùng nhập với các số nguyên tố và kiểm tra xem có khớp hay không.


</details>
<details>
<summary><b>Đáp án:</b></summary>

>```
>#include <iostream>
>
>bool isPrime(int x) {
>  if (x == 2) // Nếu người dùng nhập 2, đây là số nguyên tố
>    return true;
>  else if (x == 3) // Nếu người dùng nhập 3, đây là số nguyên tố
>    return true;
>  else if (x == 5) // Nếu người dùng nhập 5, đây là số nguyên tố
>    return true;
>  else if (x == 7) // Nếu người dùng nhập 7, đây là số nguyên tố
>    return true;
>
>  return false; // Nếu người dùng không nhập 2, 3, 5, 7, thì số này không phải số nguyên tố
>}
>
>int main() {
>  std::cout << "Enter a number 0 through 9: ";
>  int x;
>  std::cin >> x;
>
>  if (isPrime(x))
>    std::cout << "The digit is prime\n";
>  else
>    std::cout << "The digit is not prime\n";
>
>  return 0;
>}
>```

>**Đối với người đọc nâng cao:**<br>
>Nếu hàm `isPrime()` ở trên có vẻ hơi dài dòng/lặp lại thì đúng là như vậy. Chúng ta có thể viết `isPrime()` gọn hơn và hiệu quả hơn bằng cách sử dụng một số khái niệm sẽ được giải thích trong các bài học tiếp theo.
>
>- Sử dụng toán tử logic **OR** (`||`) ([Bài 6.7 - Toán tử logic]()):
>
>>```
>>bool isPrime(int x) {
>>  return x == 2 || x == 3 || x == 5 || x == 7; // Nếu người dùng nhập 2 hoặc 3 hoặc 5 hoặc 7, đây là số nguyên tố
>>}
>>```
>
>- Sử dụng câu lệnh `switch` ([Bài 8.5 - Giới thiệu về câu lệnh switch]()):
>
>>```
>>bool isPrime(int x) {
>>  switch (x) {
>>    case 2: // Nếu người dùng nhập 2
>>    case 3: // Hoặc nếu người dùng nhập 3
>>    case 5: // Hoặc nếu người dùng nhập 5
>>    case 7: // Hoặc nếu người dùng nhập 7
>>      return true; // Thì đây là số nguyên tố
>>  }
>>
>>  return false; // Ngược lại thì số này không phải số nguyên tố
>>}
>>```
</details>


**Câu hỏi #3**: Làm thế nào để giảm độ dài của đoạn code sau (không thay đổi định dạng)?
>```
>#include <iostream>
>
>bool isAllowedToTakeFunRide()
>{
>  std::cout << "How tall are you? (cm)\n";
>
>  double height{};
>  std::cin >> height;
>
>  if (height >= 140.0)
>    return true;
>  else
>    return false;
>}
>
>int main()
>{
>  if (isAllowedToTakeFunRide())
>    std::cout << "Have fun!\n";
>  else
>    std::cout << "Sorry, you're too short.\n";
>
>  return 0;
>}
>```
<details>
    <summary><b>Đáp án:</b></summary>

Chúng ta không cần câu lệnh `if` trong `isAllowedToTakeFunRide()`. Biểu thức `height >= 140.0` được đánh giá thành thành giá trị `bool`, có thể được trả về trực tiếp.
>```
>bool isAllowedToTakeFunRide()
>{
>  std::cout << "How tall are you? (cm)\n";
>
>  double height{};
>  std::cin >> height;
>
>  return height >= 140.0;
>}
>```

Bạn không bao giờ cần câu lệnh `if` có dạng:
>```
>if (condition)
>  return true;
>else
>  return false;
>```

Bởi điều này có thể được thay thế bằng câu lệnh trả về `return condition`.

Tóm lại, khi biểu thức trả về giá trị `bool` (`true` hoặc `false`), bạn có thể trực tiếp trả về giá trị của biểu thức đó thay vì sử dụng câu lệnh `if` để kiểm tra và trả về `true` hoặc `false`.
</details>



```python

```
