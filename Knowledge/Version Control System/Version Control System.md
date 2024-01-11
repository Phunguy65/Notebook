# **Version Control System**
- [**Version Control System**](#version-control-system)
  - [The basics of Version Control](#the-basics-of-version-control)
  - [Why Version Control System Is So Important?](#why-version-control-system-is-so-important)
  - [Benefits of the Version Control System](#benefits-of-the-version-control-system)
  - [Use of Version Control System:](#use-of-version-control-system)
  - [Types of Version Control Systems:](#types-of-version-control-systems)
  - [Purpose of Version Control](#purpose-of-version-control)
- [References:](#references)

## The basics of Version Control

**Version Control**, còn được gọi là **Source Control** hoặc **Revision Control** là việc theo dõi và quản lý các mã nguồn của phần mềm.

> **Version Control** cho phép những nhà phát triển dễ dàng hợp tác và chuẩn hóa mã nguồn, đồng thời tránh gây xung đột và tạo ra một vị trí tập trung duy nhất cho toàn bộ mã nguồn.

**Version Control System** là những phần mềm cung cấp các công cụ để giúp đỡ những người phát triển phần mềm dễ dàng thực hiện **Version Control**.

## Why Version Control System Is So Important?

Trong thực tế, một sản phần mềm được phát triển bởi một nhóm các nhà phát triển, dĩ nhiên họ có thể ở các địa điểm khác nhau và mỗi người trong số họ đóng góp cho một số loại chức năng / tính năng cụ thể. Vì vậy, để đóng góp cho sản phẩm, họ cần thực hiện các sửa đổi trên mã nguồn (bằng cách thêm hoặc xóa). **Version Control System** rất hữu ích trong trường hợp này:

* Với mỗi tính năng do một nhà phát triển phần mềm đảm nhận, họ sẽ độc lập thao tác tạo, thêm, xóa mã nguồn trên một "nhánh" mới (gọi là nhánh "phụ"), dựa trên mã nguồn chung của phần mềm (gọi là "nhánh" gốc).
* Các "nhánh" này có thể được hoặc không cần hợp nhất cho đến khi được một ai đó trong nhóm mà có khả năng "phê duyệt".
* Nếu được duyệt, các "nhánh" phụ được hợp nhất vào mã nguồn chính, được quản lý bởi "nhánh" gốc.
* > Mọi công việc đều được thực hiện một cách độc lập, qua đó, giúp đỡ các nhà phát triển cải thiện quá trình làm ra sản phẩm.

Ngoài ra, **Version Control System** thể hiện được sức mạnh của mình trong trường hợp:
* Giả sử, nếu một nhóm nhà phát triển thêm một số tính năng mới vào một ứng dụng và phiên bản cập nhật không hoạt động đúng cách.
* Lúc này, họ cần quay trở lại phiên bản trước đó bằng **Version Control System** thông qua một "snapshot" (lịch sử code đã được lưu lại trước đó).

## Benefits of the Version Control System

* Cải thiện chất lượng, rút ngắn thời gian phát hành sản phẩm bằng sự giao tiếp, hợp tác giữa các nhà phát triển phần mềm thông qua một hệ thống linh động, có quy tắc.
* Giảm khả năng xảy ra lỗi và xung đột trong quá trình phát triển dự án thông qua việc theo dõi mỗi thay đổi nhỏ.
* Các nhà phát triển chính của dự án, hoặc sự đóng góp quá trình phát triển dự án có thể diễn ra bất kỳ đâu mà không phụ thuộc vào các vị trí địa lý khác nhau.
* Đối với mỗi người tham gia vào dự án, mỗi người giữ một bản sao và không được hợp nhất vào phiên bản chính trừ khi bản sao đó được xác minh.
* Dễ dàng khắc phục sự cố trên phiên bản phần mềm hiện tại bằng cách quay về các phiên bản trước đó.
* Thông báo cho tất cả những ai quan tâm về dự án về Ai? Cái gì? Khi nào? Tại sao? đã thực hiện các thay đổi.

## Use of Version Control System: 

* **A repository** (kho lưu trữ): Có thể hình dung như một cơ sở dữ liệu thay đổi. Nó chứa tất cả các chỉnh sửa và các phiên bản lịch sử (snapshots) của dự án.
* **Copy of Work (sometimes called as checkout)** (Bản sao công việc, còn gọi là checkout): Đây là bản sao cá nhân của tất cả các tệp trong một dự án. Bạn có thể chỉnh sửa bản sao này mà không ảnh hưởng đến công việc của người khác và cuối cùng bạn có thể lưu các thay đổi của mình vào kho lưu trữ khi bạn đã hoàn thành việc thay đổi.
* **Working in a group**: Hãy tưởng tượng bạn đang làm việc trong một công ty, nơi bạn được yêu cầu làm việc trực tiếp trên một số dự án. Bạn không thể thay đổi mã nguồn chính vì nó đang được phát triển và bất kỳ thay đổi nào cũng có thể gây bất tiện cho người dùng. Ngoài ra, bạn đang làm việc theo nhóm nên cần hợp tác với các thành viên khác trong nhóm để điều chỉnh các thay đổi theo yêu cầu họ đề xuất. **Version Control** giúp bạn đáp ứng tất cả các yêu cầu khác nhau vào kho lưu trữ chính mà không gây ra bất kỳ thay đổi không mong muốn nào. Đó là vì bạn chỉ cần tạo ra một bản sao mã nguồn, phát triển nó độc lập, đến khi nào mã nguồn đó được chấp thuận, đơn giản là kéo mã nguồn từ bản sao, hợp lại về mã nguồn chính. Nó có thể được hình dung như...


<div align = "center">  
    <img src = "./Images/Version%20Control%20Operation.png">
    <p>Version Control Operations</p> 
</div>

## Types of Version Control Systems:

* **Local Version Control Systems** (Hệ thống kiểm soát phiên bản cục bộ): 

    * Hoạt động hoàn toàn trên máy tính cá nhân, không cần kết nối máy chủ trung tâm.
    * Chỉ quản lý phiên bản của các tập tin trên máy tính đó.
    * Dễ thiết lập và sử dụng, nhưng khó cộng tác vì không có phiên bản chung chia sẻ.
    *Ví dụ*: RCS, CVS.

* **Centralized Version Control Systems** (Hệ thống kiểm soát phiên bản tập trung):

    * Lưu trữ tất cả các phiên bản của tập tin trong một kho lưu trữ trung tâm.
    * Nhiều người dùng có thể truy cập kho lưu trữ và thực hiện thay đổi.
    * Dễ dàng cộng tác và theo dõi lịch sử thay đổi.
    * Yêu cầu kết nối máy chủ trung tâm nên phụ thuộc vào tính ổn định của máy chủ.
    *Ví dụ*: SVN, Git trong chế độ trung tâm.

<div align = "center">  
    <img src = "./Images/Centralized%20Version%20Control%20Systems.png">
    <p>Centralized Version Control Systems</p> 
</div>

* **Distributed Version Control Systems** (Hệ thống kiểm soát phiên bản phân tán):

    * Mỗi máy tính của thành viên đều có một bản sao đầy đủ của kho lưu trữ.
    * Có thể làm việc ngoại tuyến và đồng bộ hóa thay đổi sau đó.
    Cực kỳ linh hoạt và chống chịu lỗi, ít phụ thuộc vào máy chủ trung tâm.
    * Có thể phức tạp hơn để thiết lập và học so với các loại khác.
    *Ví dụ*: Git trong chế độ phân tán, Mercurial.

<div align = "center">  
    <img src = "./Images/Distributed%20Version%20Control%20Systems.png">
    <p>Distributed Version Control Systems</p> 
</div>

## Purpose of Version Control

* **Làm việc nhóm**: Nhiều người có thể cùng lúc làm việc trên cùng một dự án. Mọi người đều làm việc và chỉnh sửa bản sao của riêng mình. Tự do lựa chọn chia sẻ hoặc không những thay đổi đã thực hiện với các thành viên trong nhóm.

* **Làm việc độc lập**:   cũng cho phép một người sử dụng nhiều laptop hoặc desktop để làm việc trên cùng một dự án, vì vậy nó có giá trị ngay cả khi bạn đang làm việc một mình.

* **Quản lý lịch sử phiên bản**: **Version Control System** cung cấp quyền truy cập vào các phiên bản lịch sử của một dự án. Đây là "bảo hiểm" trong các sự cố máy tính hoặc mất dữ liệu. Nếu bất kỳ sai lầm nào được thực hiện, bạn có thể dễ dàng quay lại phiên bản trước đó. Cũng có thể hoàn tác các chỉnh sửa cụ thể mà không làm mất công việc đã thực hiện trong khi đó. Bạn có thể dễ dàng biết khi nào, tại sao và bởi ai đã chỉnh sửa bất kỳ phần nào của tệp.

# References:

* GeeksforGeeks: https://www.geeksforgeeks.org/version-control-systems/






