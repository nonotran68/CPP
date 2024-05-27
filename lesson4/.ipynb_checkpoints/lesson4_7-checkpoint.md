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
