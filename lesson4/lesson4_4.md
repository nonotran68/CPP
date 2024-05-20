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
