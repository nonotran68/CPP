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
