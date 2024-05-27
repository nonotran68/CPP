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
