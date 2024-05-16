## **Bài 2.13: <u>Cách thiết kế chương trình đầu tiên của bạn</u>**

Bây giờ, khi bạn đã học được một số kiến thức cơ bản về chương trình, chúng ta hãy xem xét kỹ hơn cách thiết kế chương trình.

Khi bạn ngồi xuống để viết chương trình, thông thường bạn sẽ có một ý tưởng nào đó, mà bạn muốn viết chương trình cho nó. Lập trình viên mới thường gặp khó khăn trong việc chuyển đổi ý tưởng đó thành mã thực tế. Nhưng hóa ra, bạn đã có sẵn nhiều kỹ năng giải quyết vấn đề cần thiết, có được từ cuộc sống hàng ngày.

Điều quan trọng nhất cần nhớ (và khó thực hiện nhất) là thiết kế chương trình của bạn trước khi bắt đầu viết mã. Trong nhiều khía cạnh, lập trình giống như kiến trúc. Điều gì sẽ xảy ra nếu bạn cố gắng xây dựng một ngôi nhà mà không theo một bản vẽ kiến trúc? Rất có khả năng, trừ khi bạn là người rất tài năng, bạn sẽ có một ngôi nhà gặp nhiều vấn đề: tường không thẳng, mái dột, v.v... Tương tự, nếu bạn cố gắng lập trình trước khi có một kế hoạch tốt để tiến lên, bạn có thể thấy rằng mã của bạn có rất nhiều vấn đề và bạn sẽ phải dành nhiều thời gian để sửa những vấn đề hoàn toàn có thể tránh được chỉ với một chút suy nghĩ trước.

Một chút lập kế hoạch trước sẽ giúp bạn tiết kiệm thời gian và giảm bớt sự thất vọng trong thời gian dài.

Trong bài học này, chúng ta sẽ trình bày một cách tiếp cận tổng quát để chuyển đổi các ý tưởng thành các chương trình chức năng đơn giản.

### **Bước thiết kế 1: Xác định mục tiêu của bạn**

Để viết một chương trình thành công, trước tiên bạn cần xác định mục tiêu của mình là gì. Lý tưởng nhất, bạn nên nêu điều này trong một hoặc hai câu. Thường thì việc thể hiện điều này như một kết quả hướng đến người dùng sẽ hữu ích. **Ví dụ:**

- Cho phép người dùng tổ chức một danh sách tên và số điện thoại liên quan.
- Tạo các hầm ngục ngẫu nhiên, thứ sẽ tạo ra các hang động thú vị.
- Tạo danh sách các khuyến nghị về cổ phiếu cho các cổ phiếu có cổ tức cao.
- Lập mô hình thời gian cần thiết để một quả bóng rơi khỏi tháp rơi xuống đất.

Mặc dù bước này có vẻ hiển nhiên, nhưng nó cũng rất quan trọng. Điều tồi tệ nhất bạn có thể làm là viết một chương trình không thực sự thực hiện những gì bạn (hoặc sếp của bạn) mong muốn!

### **Bước thiết kế 2: Xác định các yêu cầu**

Mặc dù việc xác định vấn đề của bạn giúp bạn xác định kết quả mong muốn, nhưng nó vẫn còn mơ hồ. Bước tiếp theo là suy nghĩ về các yêu cầu.

Yêu cầu là một từ mỹ miều cho cả những ràng buộc mà giải pháp của bạn cần tuân theo (ví dụ: ngân sách, thời gian, không gian, bộ nhớ, v.v.) cũng như các khả năng mà chương trình phải thể hiện để đáp ứng nhu cầu của người dùng. Lưu ý rằng các yêu cầu của bạn cũng nên tập trung vào "cái gì", không phải "như thế nào".

**Ví dụ:**

- Số điện thoại nên được lưu để có thể truy xuất lại sau.
- Hầm ngục ngẫu nhiên luôn phải chứa một lối đi từ lối vào đến lối ra.
- Các khuyến nghị về cổ phiếu nên tận dụng dữ liệu giá lịch sử.
- Người dùng có thể nhập chiều cao của tháp.
- Chúng ta cần một phiên bản có thể kiểm thử trong vòng 7 ngày.
- Chương trình phải tạo ra kết quả trong vòng 10 giây kể từ khi người dùng gửi yêu cầu.
- Chương trình phải chạy ổn định trong hơn 99,9% phiên sử dụng của người dùng.

Một vấn đề duy nhất có thể dẫn đến nhiều yêu cầu và giải pháp không được coi là “hoàn thành” cho đến khi đáp ứng tất cả các yêu cầu đó.

### **Bước thiết kế 3: Xác định công cụ, mục tiêu và phương án dự phòng của bạn**

Khi bạn là một lập trình viên dày dạn kinh nghiệm, có nhiều bước khác thường diễn ra tại thời điểm này, bao gồm:

- Xác định kiến trúc mục tiêu và / hoặc hệ điều hành mà chương trình của bạn sẽ chạy trên đó.
- Xác định bộ công cụ bạn sẽ sử dụng.
- Xác định xem bạn sẽ viết chương trình một mình hay là một phần của nhóm.
- Xác định chiến lược kiểm thử / phản hồi / phát hành của bạn.
- Xác định cách bạn sẽ sao lưu mã của mình.

Tuy nhiên, đối với một lập trình viên mới, câu trả lời cho những câu hỏi này thường đơn giản: Bạn đang viết một chương trình cho mục đích sử dụng của riêng bạn, một mình, trên hệ thống của riêng bạn, sử dụng một IDE mà bạn đã tải xuống và mã của bạn có thể không được ai khác ngoài bạn sử dụng. Điều này giúp mọi thứ trở nên dễ dàng.

Tuy nhiên, nếu bạn định làm việc với bất kỳ thứ gì phức tạp, bạn nên có kế hoạch sao lưu mã của mình. Chỉ nén hoặc sao chép thư mục vào một vị trí khác trên máy tính của bạn là không đủ (mặc dù điều này tốt hơn là không làm gì). Nếu hệ thống của bạn bị lỗi, bạn sẽ mất tất cả. Một chiến lược sao lưu tốt bao gồm việc sao chép mã của bạn ra khỏi hệ thống của bạn hoàn toàn. Có rất nhiều cách dễ dàng để thực hiện việc này: Nén tệp và gửi email cho chính bạn, tải lên dịch vụ lưu trữ đám mây (ví dụ: **Dropbox**), sử dụng giao thức truyền tệp (ví dụ: **SFTP**) để tải lên máy khác, sao chép nó sang máy khác trên mạng cục bộ của bạn hoặc sử dụng hệ thống quản lý phiên bản nằm trên máy khác hoặc trên đám mây (ví dụ: **github**). Hệ thống quản lý phiên bản có thêm lợi thế không chỉ có thể khôi phục các tệp của bạn mà còn có thể đưa chúng trở lại phiên bản trước đó.

### **Bước thiết kế 4: Chia nhỏ các vấn đề khó thành các vấn đề dễ**

Ngoài đời thực, chúng ta thường cần thực hiện các tác vụ rất phức tạp. Cố gắng tìm ra cách thực hiện các nhiệm vụ này có thể rất khó khăn. Trong những trường hợp như vậy, chúng ta thường sử dụng **phương pháp giải quyết vấn đề từ trên xuống (*top-down*)**. Nghĩa là, thay vì giải quyết một tác vụ phức tạp lớn, chúng ta chia tác vụ đó thành nhiều tác vụ phụ, mỗi tác vụ riêng lẻ đều dễ giải quyết hơn. Nếu các tác vụ phụ đó vẫn quá khó giải quyết, chúng có thể được chia nhỏ hơn nữa. Bằng cách liên tục chia các tác vụ phức tạp thành các tác vụ đơn giản hơn, cuối cùng bạn có thể đến một điểm mà mỗi tác vụ riêng lẻ đều có thể xử lí dễ dàng.

Hãy xem một ví dụ về điều này. Giả sử chúng ta muốn dọn dẹp nhà cửa. Bậc thang nhiệm vụ hiện tại của chúng ta trông như thế này:
- Dọn dẹp nhà cửa

Dọn dẹp toàn bộ ngôi nhà là một công việc khá lớn để hoàn thành trong một lần liên tục. Vì vậy hãy chia nhỏ nó thành các tác vụ phụ:

- Dọn dẹp nhà cửa
    - Hút bụi thảm
    - Lau chùi phòng tắm
    - Vệ sinh nhà bếp

Bây giờ nó dễ quản lý hơn, vì bây giờ chúng ta có các tác vụ phụ mà chúng ta có thể tập trung vào từng tác vụ. Tuy nhiên, chúng ta có thể chia nhỏ một số tác vụ này thành các tác vụ nhỏ hơn:

- Dọn dẹp nhà cửa
    - Hút bụi thảm
    - Lau chùi phòng tắm
        - Cọ toilet (ugh!)
        - Rửa bồn rửa mặt
    - Vệ sinh nhà bếp
        - Dọn dẹp mặt bàn
        - Lau chùi mặt bàn
        - Cọ bồn rửa mặt
        - Đem rác đi vứt
Bây giờ chúng ta có một hệ thống phân cấp các tác vụ, không có tác vụ nào đặc biệt khó khăn. Bằng cách hoàn thành từng mục phụ tương đối dễ quản lý này, chúng ta có thể hoàn thành tác vụ tổng thể khó khăn hơn là ***dọn dẹp nhà cửa***.

Cách khác để tạo ra một hệ thống phân cấp các nhiệm vụ là thực hiện theo **phương pháp từ dưới lên (*bottom-up*)**. Trong phương pháp này, chúng ta sẽ bắt đầu từ một danh sách các nhiệm vụ dễ dàng và xây dựng hệ thống phân cấp bằng cách nhóm chúng lại với nhau.

Ví dụ, nhiều người phải đi làm hoặc đi học vào các ngày trong tuần, vì vậy hãy nói rằng chúng ta muốn giải quyết vấn đề **“đi làm”**. Nếu bạn được hỏi bạn đã làm những công việc gì vào buổi sáng để đi từ giường đến cơ quan, bạn có thể đưa ra danh sách sau:

- Lấy quần áo
- Mặc quần áo
- Ăn sáng
- Đi làm
- Đánh răng
- Ra khỏi giường
- Chuẩn bị bữa ăn sáng
- Lấy xe đạp
- Đi tắm

Sử dụng phương pháp ***bottom-up***, chúng ta có thể tổ chức chúng thành một hệ thống phân cấp các mục bằng cách tìm kiếm các cách để nhóm các mục có điểm tương đồng với nhau:

- Từ giường đến cơ quan
    - Những thứ trong phòng ngủ
        - Tắt báo thức
        - Ra khỏi giường
        - Lấy quần áo
    - Những thứ trong phòng tắm
        - Đi tắm
        - Mặc quần áo
        - Đánh răng
    - Những thứ cho bữa ăn sáng
        - Pha cà phê hoặc trà
        - Ăn ngũ cốc
    - Những thứ về phương tiện đi lại
        - Lên xe đạp
        - Đi làm

Hóa ra, các hệ thống phân cấp tác vụ này cực kỳ hữu ích trong lập trình, bởi vì một khi bạn có hệ thống phân cấp tác vụ, về bản chất bạn đã xác định cấu trúc của toàn bộ chương trình. Tác vụ cấp cao nhất (trong trường hợp này là *“Dọn dẹp nhà cửa”* hoặc *“Đi làm”*) trở thành `main()` (bởi vì đó là vấn đề chính bạn đang cố gắng giải quyết). Các mục phụ trở thành các hàm trong chương trình.

Nếu một trong các mục (hàm) có vẻ quá khó để triển khai, chỉ cần chia nhỏ mục đó thành nhiều mục phụ / hàm phụ. Cuối cùng, bạn sẽ đạt đến một điểm mà mỗi hàm trong chương trình của bạn đều có thể triển khai một cách đơn giản.



### **Bước thiết kế 5: Xác định trình tự các sự kiện**

Bây giờ chương trình của bạn đã có cấu trúc, đã đến lúc xác định cách liên kết tất cả các tác vụ lại với nhau. Bước đầu tiên là xác định trình tự các sự kiện sẽ được thực hiện. Ví dụ, khi bạn dậy vào buổi sáng, bạn thực hiện các tác vụ ở trên theo thứ tự nào? Nó có thể trông giống như thế này:

1. Những thứ trong phòng ngủ
2. Những thứ trong phòng tắm
3. Những thứ cho bữa ăn sáng
4. Những thứ về phương tiện đi lại

Nếu chúng ta đang viết một chương trình tính toán, chúng ta có thể thực hiện các thao tác theo thứ tự này:

- Lấy số thứ nhất từ người dùng
- Lấy phép toán từ người dùng
- Lấy số thứ hai từ người dùng
- Tính toán kết quả
- In kết quả

Lúc này, chúng ta đã sẵn sàng để triển khai.

### **Bước triển khai 1: Vạch ra hàm chính của bạn**

Bây giờ chúng ta đã sẵn sàng để bắt đầu triển khai. Các trình tự trên có thể được sử dụng để phác thảo chương trình chính của bạn. Hiện tại, đừng lo lắng về đầu vào và đầu ra.

>```
>int main()
>{
>//    doBedroomThings(); // Bình luận vì hàm chưa được định nghĩa
>//    doBathroomThings(); // Bình luận vì hàm chưa được định nghĩa
>//    doBreakfastThings(); // Bình luận vì hàm chưa được định nghĩa
>//    doTransportationThings(); // Bình luận vì hàm chưa được định nghĩa
>
>    return 0;
>}
>```

Hoặc trong trường hợp của chương trình tính toán:
>```
>int main()
>{
>      // Lấy số thứ nhất từ người dùng // Bình luận vì hàm chưa được định nghĩa
>//    getUserInput();
>
>      // Lấy phép toán từ người dùng // Bình luận vì hàm chưa được định nghĩa
>//    getMathematicalOperation();
>
>      // Lấy số thứ hai từ người dùng // Bình luận vì hàm chưa được định nghĩa
>//    getUserInput();
>
>      // Tính toán kết quả // Bình luận vì hàm chưa được định nghĩa
>//    calculateResult();
>
>      // In kết quả // Bình luận vì hàm chưa được định nghĩa
>//    printResult();
>
>    return 0;
}
>```

Lưu ý rằng nếu bạn định sử dụng phương pháp "phác thảo" này để xây dựng chương trình của mình, các hàm của bạn sẽ không được biên dịch vì các định nghĩa chưa tồn tại. Bình luận các lệnh gọi hàm cho đến khi bạn sẵn sàng triển khai định nghĩa hàm là một cách để giải quyết việc này (và là cách chúng ta sẽ trình bày ở đây). Ngoài ra, bạn có thể tạo các khung (stub) cho các hàm của mình (tạo các hàm giữ chỗ với thân rỗng) để chương trình của bạn có thể biên dịch.

### **Bước triển khai 2: Triển khai từng hàm**

Trong bước này, đối với mỗi hàm, bạn sẽ thực hiện ba điều:
- Xác định kiểu hàm (đầu vào và đầu ra)
- Viết hàm
- Kiểm tra hàm

Nếu các hàm của bạn được phân tích đủ chi tiết, thì mỗi hàm sẽ trở nên khá đơn giản và dễ dàng. Nếu một hàm nhất định vẫn có vẻ quá phức tạp để triển khai, có lẽ nó cần được chia thành các hàm phụ có thể triển khai dễ dàng hơn (hoặc có thể bạn đã thực hiện sai thứ tự và cần xem xét lại trình tự các sự kiện của mình).

Hãy thực hiện hàm đầu tiên từ ví dụ chương trình máy tính cầm tay:

>```
>#include <iostream>
>
>// Triển khai đầy đủ của hàm getUserInput
>int getUserInput()
>{
>    std::cout << "Nhập một số nguyên: ";
>    int input{};
>    std::cin >> input;
>
>    return input;
>}
>
>int main()
>{
>    // Lấy số thứ nhất từ người dùng
>    int value{ getUserInput() }; // Lưu ý rằng chúng ta đã bao gồm mã ở đây để kiểm tra giá trị trả về!
>    std::cout << value << '\n'; // mã gỡ lỗi để đảm bảo getUserInput() hoạt động, chúng ta sẽ xóa bỏ sau này
>
>    // Lấy phép toán từ người dùng
>//    getMathematicalOperation();
>
>    // Lấy số thứ hai từ người dùng
>//    getUserInput();
>
>    // Tính toán kết quả
>//    calculateResult();
>
>    // In kết quả
>//    printResult();
>
>    return 0;
>}
>```

Đầu tiên, chúng ta xác định rằng hàm `getUserInput` không nhận bất kỳ đối số nào và sẽ trả về một giá trị kiểu `int` cho người gọi. Điều đó được phản ánh trong kiểu hàm có giá trị trả về là `int` và không có tham số. Tiếp theo, chúng ta đã viết thân hàm, bao gồm 4 câu lệnh đơn giản. Cuối cùng, chúng ta đã triển khai một số mã tạm thời trong hàm `main` để kiểm tra xem hàm `getUserInput` (bao gồm cả giá trị trả về của nó) có hoạt động chính xác hay không.

Chúng ta có thể chạy chương trình này nhiều lần với các giá trị đầu vào khác nhau và đảm bảo rằng chương trình hoạt động như mong đợi tại thời điểm này. Nếu chúng ta tìm thấy thứ gì đó không hoạt động, chúng ta biết vấn đề nằm ở đoạn mã vừa viết.

Khi chúng ta tin tưởng chương trình hoạt động như dự định cho đến thời điểm này, chúng ta có thể xóa mã kiểm tra tạm thời và tiến hành triển khai hàm tiếp theo (hàm `getMathematicalOperation`). Chúng ta sẽ không hoàn thành chương trình trong bài học này, vì trước tiên chúng ta cần đề cập thêm một số chủ đề bổ sung.

**Ghi nhớ:** Không triển khai toàn bộ chương trình của bạn trong một lần. Hãy thực hiện từng bước, kiểm tra từng bước trước khi tiến hành.

>**Nội dung liên quan**<br>
>Chúng tôi sẽ đề cập chi tiết hơn về kiểm thử trong bài học **9.1 - Giới thiệu về kiểm thử.**

### **Bước triển khai 3: Kiểm thử cuối cùng**

Khi chương trình của bạn được “hoàn thành”, bước cuối cùng là kiểm tra toàn bộ chương trình và đảm bảo nó hoạt động như dự định. Nếu nó không hoạt động, hãy sửa chữa nó.

### **Lời khuyên khi viết chương trình**

- **Giữ cho chương trình của bạn đơn giản lúc bắt đầu:** Thường thì các lập trình viên mới có tầm nhìn vĩ mô về tất cả những điều họ muốn chương trình của mình thực hiện. "Tôi muốn viết một trò chơi nhập vai với đồ họa và âm thanh, quái vật và ngục tối ngẫu nhiên, với một thị trấn bạn có thể đến thăm để bán những vật phẩm bạn tìm thấy trong ngục tối." Nếu bạn cố gắng viết thứ gì đó quá phức tạp để bắt đầu, bạn sẽ trở nên quá tải và nản lòng vì thiếu tiến bộ. Thay vào đó, hãy biến mục tiêu đầu tiên của bạn trở nên đơn giản nhất có thể, thứ gì đó chắc chắn nằm trong tầm với của bạn. Ví dụ: "Tôi muốn có thể hiển thị một vùng 2 chiều trên màn hình".
- **Thêm các tính năng theo thời gian:** Sau khi chương trình đơn giản của bạn hoạt động tốt, bạn có thể thêm các tính năng vào đó. Ví dụ, một khi bạn có thể hiển thị vùng không gian, hãy thêm một nhân vật có thể đi lại xung quanh. Sau khi bạn có thể đi lại, hãy thêm các bức tường có thể cản trở tiến trình của bạn. Khi bạn có tường, hãy xây dựng một thị trấn đơn giản từ chúng. Khi bạn có một thị trấn, hãy thêm thương gia. Bằng cách thêm từng tính năng một cách gia tăng, chương trình của bạn sẽ dần trở nên phức tạp hơn mà không khiến bạn quá tải trong quá trình này.
- **Tập trung vào một tác vụ tại một thời điểm:** Đừng cố gắng mã hóa tất cả mọi thứ cùng một lúc và đừng phân tán sự chú ý của bạn trên nhiều tác vụ. Tập trung vào một tác vụ tại mỗi một thời điểm. Thà có một tác vụ hoạt động và năm tác vụ chưa được bắt đầu còn hơn là sáu tác vụ hoạt động nửa vời. Nếu bạn phân tán sự chú ý, bạn có nhiều khả năng mắc lỗi và quên các chi tiết quan trọng.
- **Kiểm tra từng phần của mã khi bạn chạy:** Các lập trình viên mới thường sẽ viết toàn bộ chương trình trong một lần. Sau đó, khi họ biên dịch nó lần đầu tiên, trình biên dịch báo cáo hàng trăm lỗi. Điều này không chỉ có thể gây ra sự nản lòng, mà nếu mã của bạn không hoạt động, thì việc tìm ra nguyên nhân có thể rất khó. Thay vào đó, hãy viết một đoạn mã, sau đó biên dịch và kiểm tra ngay lập tức. Nếu nó không hoạt động, bạn sẽ biết chính xác vấn đề nằm ở đâu và sẽ dễ dàng sửa chữa. Khi bạn chắc chắn rằng mã hoạt động, hãy chuyển sang phần tiếp theo và lặp lại. Việc viết xong mã của bạn có thể mất nhiều thời gian hơn, nhưng khi bạn hoàn thành, toàn bộ chương trình sẽ hoạt động và bạn không cần phải mất gấp đôi thời gian để tìm ra lý do tại sao nó không hoạt động.
- **Đừng đầu tư vào việc hoàn thiện mã sớm:** Bản nháp đầu tiên của một tính năng (hoặc chương trình) hiếm khi tốt. Hơn nữa, các chương trình có xu hướng phát triển theo thời gian, khi bạn thêm các khả năng và tìm ra cách tốt hơn để cấu trúc mọi thứ. Nếu bạn đầu tư quá sớm vào việc "đánh bóng" mã của mình (thêm nhiều tài liệu, tuân thủ đầy đủ các thực hành tốt nhất, thực hiện tối ưu hóa), bạn có nguy cơ mất tất cả khoản đầu tư đó khi cần thay đổi mã. Thay vào đó, hãy làm cho các tính năng của bạn hoạt động tối thiểu, sau đó tiếp tục. Khi bạn tin tưởng vào các giải pháp của mình, hãy áp dụng các lớp "đánh bóng" tiếp theo. Đừng hướng đến sự hoàn hảo - các chương trình không tầm thường không bao giờ hoàn hảo và luôn có thêm việc gì đó có thể được thực hiện để cải thiện chúng. Hãy đạt đến mức “đủ tốt” và tiếp tục.
- **Tối ưu hóa cho khả năng bảo trì, không phải hiệu suất:** Có một câu nói nổi tiếng (của Donald Knuth) rằng *"premature optimization is the root of all evil”* (*"Tối ưu hoá sớm là khởi đầu của tất cả tội ác."* ). Các lập trình viên mới thường dành quá nhiều thời gian suy nghĩ về cách tối ưu hóa vi mô code của họ (ví dụ: cố gắng tìm ra câu lệnh nào trong 2 câu lệnh chạy nhanh hơn). Điều này hiếm khi quan trọng. Hầu hết các lợi ích về hiệu suất đến từ cấu trúc chương trình tốt, sử dụng các công cụ và khả năng phù hợp cho vấn đề đang xử lý và tuân theo các thực hành tốt nhất. Thời gian bổ sung nên được sử dụng để cải thiện khả năng bảo trì của mã. Tìm kiếm và loại bỏ các đoạn mã trùng lặp. Chia các hàm dài thành các hàm ngắn hơn. Thay thế mã khó sử dụng hoặc khó hiểu bằng thứ gì đó tốt hơn. Kết quả cuối cùng sẽ là mã dễ cải thiện và tối ưu hóa hơn sau này (sau khi bạn đã xác định được nơi thực sự cần tối ưu hóa) và ít lỗi hơn. Chúng tôi cung cấp một số đề xuất bổ sung trong bài học **3.10 - Tìm kiếm các vấn đề trước khi chúng trở thành rắc rối.**

>***Một hệ thống phức tạp hoạt động được luôn được phát triển từ một hệ thống đơn giản hoạt động được
.***<br>
— **John Gall, SYSTEMANTICS: How Systems Work and Especially How They Fail, trang 71**

### **Kết luận**

Nhiều lập trình viên mới thường rút ngắn quy trình thiết kế (bởi vì nó có vẻ tốn nhiều công sức và/hoặc không thú vị bằng việc viết mã). Tuy nhiên, đối với bất kỳ dự án nào không tầm thường, việc thực hiện theo các bước này sẽ giúp bạn tiết kiệm được rất nhiều thời gian trong tương lai. Dành một chút thời gian lên kế hoạch trước sẽ giúp bạn tiết kiệm được rất nhiều công sức gỡ rối lỗi về sau.

>**Ý chính**<br>
>Dành một chút thời gian suy nghĩ về cách cấu trúc chương trình của bạn ngay từ đầu sẽ dẫn đến mã tốt hơn và ít thời gian hơn để tìm và sửa lỗi.
>
>*Tôi cho rằng đây có thể là điều quan trọng nhất trong lập trình và một số người trong chúng tôi, giống như tôi lúc đầu, đã coi nhẹ nó.*<br>
>**— Bạn đọc Emeka Daniel, BÌNH LUẬN TRÊN LEARNCPP.COM**

Khi bạn trở nên thoải mái hơn với những khái niệm và mẹo này, chúng sẽ bắt đầu đến với bạn một cách tự nhiên hơn. Cuối cùng, bạn sẽ đạt đến mức có thể viết toàn bộ hàm (và các chương trình ngắn) mà không cần lập kế hoạch trước.
