## **Bài 2.6: <u>Tại sao hàm hữu ích và cách sử dụng chúng hiệu quả</u>**

Bây giờ, khi chúng ta đã tìm hiểu về hàm và một số khả năng cơ bản của chúng, hãy cùng xem xét kỹ hơn lý do tại sao chúng hữu ích.

### **Tại sao sử dụng hàm?**

Lập trình viên mới thường hỏi, "Chẳng phải chúng ta chỉ cần đặt tất cả mã bên trong hàm `main` sao?" Đối với các chương trình đơn giản, bạn hoàn toàn có thể làm được điều đó. Tuy nhiên, hàm cung cấp một số lợi ích khiến chúng cực kỳ hữu ích trong các chương trình có độ dài hoặc phức tạp không tầm thường.

**1**. **Tổ chức** - Khi chương trình ngày càng phức tạp, việc chứa tất cả mã bên trong hàm `main` sẽ trở nên phức tạp hơn. Hàm gần giống như một chương trình nhỏ mà chúng ta có thể viết riêng biệt với chương trình chính, mà không cần phải nghĩ đến phần còn lại của chương trình trong khi viết. Điều này cho phép chúng ta phân tách một chương trình phức tạp thành các phần nhỏ hơn, dễ quản lý hơn, giúp giảm thiểu tổng thể tính phức tạp của chương trình.

**2**. **Tái sử dụng** - Sau khi một hàm được viết, nó có thể được gọi nhiều lần từ bên trong chương trình. Điều này tránh được việc sao chép mã (**"Đừng lặp lại chính mình"**) và giảm thiểu khả năng xảy ra lỗi sao chép/dán. Hàm cũng có thể được chia sẻ với các chương trình khác, giúp giảm lượng mã phải viết từ đầu (và kiểm tra lại) mỗi lần.

**3**. **Kiểm thử** - Do hàm giảm thiểu sự trùng lặp mã, nên ngay từ đầu sẽ có ít mã hơn để kiểm thử. Ngoài ra, vì các hàm là các đơn vị độc lập, nên một khi chúng ta đã kiểm thử một hàm để đảm bảo nó hoạt động, chúng ta không cần phải kiểm thử lại trừ khi chúng ta thay đổi nó. Điều này làm giảm lượng mã chúng ta phải kiểm thử cùng một lúc, giúp việc tìm lỗi (hoặc tránh lỗi ngay từ đầu) dễ dàng hơn nhiều.



**4**. **Mở rộng** - Khi chúng ta cần mở rộng chương trình để xử lý một trường hợp mà trước đây nó không xử lý được, hàm cho phép chúng ta thực hiện thay đổi ở một vị trí và thay đổi đó sẽ có hiệu lực mỗi lần hàm được gọi.

**5**. **Trừu tượng** - Để sử dụng một hàm, bạn chỉ cần biết tên, đầu vào, đầu ra và vị trí của nó. Bạn không cần biết cách hoạt động của nó hoặc mã khác mà nó phụ thuộc để sử dụng nó. Điều này làm giảm lượng kiến thức cần thiết để sử dụng mã của người khác (bao gồm mọi thứ trong thư viện chuẩn).

### **Sử dụng hàm hiệu quả**

Một trong những thách thức lớn nhất mà lập trình viên mới gặp phải (bên cạnh việc học ngôn ngữ) là hiểu khi nào và làm thế nào để sử dụng hàm một cách hiệu quả. Dưới đây là một vài hướng dẫn cơ bản để viết hàm:

- Nhóm các câu lệnh xuất hiện nhiều lần trong chương trình thường nên được chuyển thành một hàm. Ví dụ, nếu chúng ta đang đọc dữ liệu nhập từ người dùng nhiều lần theo cùng một cách, đó là một ứng dụng tuyệt vời cho hàm. Nếu chúng ta xuất ra thứ gì đó theo cùng một cách ở nhiều vị trí khác nhau, thì đó cũng là một ứng dụng tuyệt vời cho hàm.

- Mã có một tập hợp đầu vào và đầu ra được xác định rõ ràng là một ứng cử viên cho hàm (đặc biệt nếu nó phức tạp). Ví dụ, nếu chúng ta có một danh sách các mục mà chúng ta muốn sắp xếp, thì mã để thực hiện việc sắp xếp sẽ tạo ra một hàm tuyệt vời, ngay cả khi nó chỉ được thực hiện một lần. Đầu vào là danh sách chưa được sắp xếp và đầu ra là danh sách đã được sắp xếp. Một hàm tiềm năng tốt khác là mã mô phỏng việc lăn một con xúc xắc 6 mặt. Chương trình hiện tại của bạn chỉ có thể sử dụng nó ở một vị trí, nhưng nếu bạn biến nó thành một hàm, nó đã sẵn sàng để được tái sử dụng nếu sau này bạn mở rộng chương trình hoặc trong một chương trình tương lai.

- Một hàm thường nên thực hiện một (và chỉ một) tác vụ.

- Khi một hàm trở nên quá dài, quá phức tạp hoặc khó hiểu, nó có thể được chia thành nhiều hàm phụ. Đây được gọi là **refactoring (tái cấu trúc)**. Chúng tôi sẽ thảo luận thêm về tái cấu trúc trong **bài học 3.10 - Tìm ra vấn đề trước khi chúng trở thành rắc rối.**


Thông thường, khi học C++, bạn sẽ viết nhiều chương trình liên quan đến 3 nhiệm vụ phụ:

- Đọc dữ liệu nhập từ người dùng
- Tính toán một giá trị từ các đầu vào
- In ra giá trị đã tính toán

Đối với các chương trình đơn giản (ví dụ: ít hơn 20 dòng code), một số hoặc tất cả các nhiệm vụ này có thể được thực hiện trong hàm main. Tuy nhiên, đối với các chương trình dài hơn (hoặc chỉ để thực hành), mỗi nhiệm vụ này đều là một ứng dụng tuyệt vời cho một hàm riêng lẻ.

### **Sai lầm của lập trình viên mới**

Lập trình viên mới thường kết hợp việc tính toán giá trị và in ra giá trị đã tính toán thành một hàm duy nhất. Tuy nhiên, điều này vi phạm quy tắc “chỉ một nhiệm vụ” cho các hàm. Một hàm tính toán giá trị nên trả về giá trị đó cho hàm gọi và để hàm gọi quyết định làm gì với giá trị đã tính toán (chẳng hạn như gọi một hàm khác để in ra giá trị).
