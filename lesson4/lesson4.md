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
***a)*** Kết quả của `13 / 5` là gì?
<details>
<summary><b>Lời giải:</b></summary>

`13 / 5` = `2` dư `3`. Số dư bị loại bỏ, chỉ còn `2`.
</details>


***b)*** Kết quả của `-13 / 5` là gì?
<details>
<summary><b>Lời giải:</b></summary>
    
`-13 / 5` = `-2` dư `-3`. Số dư bị loại bỏ, chỉ còn `-2`.
</details>


```python

```
