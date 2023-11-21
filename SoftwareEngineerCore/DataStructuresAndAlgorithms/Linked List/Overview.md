# **Linked List - Danh sách liên kết**

- [**Linked List - Danh sách liên kết**](#linked-list---danh-sách-liên-kết)
- [What is a Linked List?](#what-is-a-linked-list)
- [Linked Lists is an Abstract Data Type](#linked-lists-is-an-abstract-data-type)
- [Why Linked Lists?](#why-linked-lists)
  - [Arrays Overview](#arrays-overview)
  - [How to access array elements in constant time?](#how-to-access-array-elements-in-constant-time)
  - [Pros \&\& Cons Array](#pros--cons-array)
  - [Pros \&\& Cons Linked List](#pros--cons-linked-list)
  - [Comparison of Linked Lists with Arrays and Dynamic Arrays](#comparison-of-linked-lists-with-arrays-and-dynamic-arrays)
  - [Summary](#summary)


# What is a Linked List?

**Linked List** - **Danh sách liên kết**, là một cấu trúc dữ liệu được sử dụng để lưu trữ các tập hợp dữ liệu.
Một **Danh sách liên kết** có các thuộc tính sau:

- Các phần tử kế tiếp được kết nối bằng con trỏ.
- Phần tử cuối cùng trỏ đến NULL.
- Có thể tăng hoặc giảm kích thước trong quá trình chương trình thực thi.
- Có thể được thực hiện miễn là được yêu cầu (cho đến khi bộ nhớ hệ thống cạn kiệt).
- Không lãng phí bộ nhớ (nhưng tốn thêm cho con trỏ).
  ![Minh họa danh sách liên kết](Images/Linked%20List%20Illustration.jpg)

# Linked Lists is an Abstract Data Type

**Các operations cơ bản của Danh sách liên kết**:

- **Insertion**: Thêm một (nhiều) phần tử vào danh sách liên kết.
- **Traversal**: Truy cập tuần tự các phần tử trong danh sách liên kết.
- **Deletion**: Xóa một (nhiều) phần tử trong danh sách liên kết.
- **Searching**: Tìm kiếm dữ liệu của danh sách liên kết bằng giá trị.
- **Updating**: Cập nhật lại giá trị cho dữ liệu của phần tử danh sách liên kết.
- **Sorting**: Tổ chức dữ liệu của danh sách liên kết theo một dạng cụ thể.
- **Merging**: Nối bất kì hai danh sách liên kết có cùng kiểu dữ liệu.

# Why Linked Lists?

Có rất nhiều cấu trúc dữ liệu khác làm điều tương tự như Linked List. Trong số đó phải kể đến **Array** - một cấu trúc dữ liệu có nhiều điểm tương đồng với **Linked List**

## Arrays Overview

Một vùng bộ nhớ liên tục được cấp phát cho toàn bộ mảng để chứa các phần tử của mảng.

Các phần tử mảng có thể được truy cập trong thời gian hằng số (constant time) bằng cách sử dụng chỉ số của phần tử cụ thể làm chỉ số con.

![Minh họa mảng](Images/Arrays%20Illustration.png)

## How to access array elements in constant time?

Để truy cập một phần tử mảng, địa chỉ của một phần tử được tính như một offset (phần bù) từ địa chỉ cơ sở của mảng và cần một phép nhân để tính toán những gì được cho là thêm vào địa chỉ cơ sở để lấy địa chỉ bộ nhớ của phần tử, nghĩa là:

- 1. Tính toán **kích thước của một phần tử của kiểu dữ liệu**.
- 2. **Nhân kết quả từ _(1)_ chỉ số của phần tử đó** để nhận giá trị được thêm vào địa chỉ cơ sở.

> **_Quá trình này thực hiện một phép nhân và một phép cộng. Vì hai hoạt động này mất constant time, chúng ta có thể nói việc truy cập mảng có thể được thực hiện trong constant time._**

## Pros && Cons Array

- Ưu điểm của mảng:

  - Đơn giản và dễ sử dụng.
  - Truy cập nhanh hơn vào các phần tử (constant time).
  - Các khối bộ nhớ liền kề, vì vậy bất kỳ phần tử mảng nào cũng sẽ ở gần các phần tử lân cận của nó. Điều này được hưởng lợi rất nhiều từ các phương pháp bộ nhớ đệm CPU hiện đại.

- Nhược điểm của mảng:

  - Cấp phát trước tất cả các bộ nhớ cần thiết và lãng phí không gian bộ nhớ cho các chỉ mục trong mảng trống.
  - **Fixed size**: Kích thước của mảng là tĩnh (chỉ định kích thước mảng trước khi sử dụng).
  - **One block allocation**: Để cấp phát mảng ngay từ đầu, đôi khi có thể không lấy được bộ nhớ cho mảng hoàn chỉnh (nếu kích thước mảng lớn).
  - **Complex position-based insertion**(Chèn phần tử vào một ví trí bất kỳ phức tạp): Để chèn một phần tử tại một vị trí nhất định, chúng ta có thể cần phải dịch chuyển các phần tử hiện có. Thao tác này sẽ tạo vị trí để chúng ta chèn phần tử mới vào vị trí mong muốn. Nếu vị trí mà chúng ta muốn thêm một phần tử nằm ở đầu, thì thao tác dịch chuyển sẽ rất tốn kém. (Vui lòng đọc tại ![đây] để biết thêm về mảng!)

## Pros && Cons Linked List

- Ưu điểm của danh sách liên kết:

  - Mở rộng kích thước của danh sách liên kết với constant time. (Các thao tác thêm phần tử vào danh sách liên kết)
  - Giảm kích thước của danh sách liên kết với constant time. (Các thao tác xóa phần tử của danh sách liên kết.) **_[cần kiểm tra]_**

- Nhược điểm của danh sách liên kết:

  - Nhược điểm chính của danh sách liên kết là thời gian truy cập vào các phần tử:

    - Để truy cập vào một phần tử, phải duyệt tuần tự từng phần tử, vì vậy trường hợp xấu nhất danh sách liên kết cần _O(n)_.

  - Bộ nhớ phân tán, đôi khi là một lợi thế nhưng đồng nghĩa đánh đổi với việc truy xuất dữ liệu.
  - Khó thao tác, cần các kĩ thuật đặc biệt.

## Comparison of Linked Lists with Arrays and Dynamic Arrays

|          **Parameter**          |                               **Linked List**                               | **Array** |    **Dynamic array**    |
| :-----------------------------: | :-------------------------------------------------------------------------: | :-------: | :---------------------: |
|            Indexing             |                                    O(n)                                     |   O(1)    |          O(1)           |
| Insertion/Deletion at beginning |                                    O(1)                                     |    N/A    |          O(n)           |
|    Insertion/Deletion at end    | O(n) nếu không biết phần tử cuối cùng.<br/>O(1) nếu biết phần tử cuối cùng. |    N/A    | O(1) nếu còn chỗ trống. |
| Insertion/Deletetion in middle  |                             search time + O(1)                              |    N/A    |          O(n)           |
|          Wasted space           |                                    O(n)                                     |     0     |          O(n)           |

## Summary

***Linked List - Danh sách liên kết rất hữu ích trong các trường hợp sau:***

- Cấp phát kích thước bộ nhớ cho dữ liệu tùy ý (tại thời điểm biên dịch).
- Thực hiện các thao tác Insert/Remove với tần suất cao.
- Tần suất tìm kiếm phần tử ở mức thấp.
