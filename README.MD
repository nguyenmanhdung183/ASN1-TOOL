============CÁCH CHẠY=================



-> cái bản tin to nó sễ chèn protocol vào trước cái IE sau đó thêm element-> gen message
-> bản tin về IE nó sẽ chỉ chèn protocol vào trước cái IE thôi


============= DỮ LIỆU CƠ BẢN - NODE CUỐI==============
ENUM -> cần fix thêm
INTERGER ->ok -> thiếu
INTERGER no ext -> ok -> thiếu
OCTET STRING ->done -> thiếu
BIT STRING  -> dùng ASN1BitStr32 -> chưa xong, cần check cho có size và ko có size
PRINTABLE STRING -> done-> nhưng thiếu 1 số hàm


===========================
sau khi xong các trường cơ bản - .h .c thì cần tổng quát về node khác node cuối -> XÂY STRUCT, CÁC HÀM (TÌM TEMPLATE)
sau đó từ pdf gen ra dữ liệu json (sẽ không dùng dùng excel nữa) về thông tin dữ liệu cơ bản và mối quan hệ hierachy với các node cha

SEQUENCE
PROTOCOL IE
PROTOCOL IE SINGALE CONTAINER
PROTOCOL IE CONTAINER
CHOICE  -> chưa xong
CLASS
CONTAINER PAIR


==========================================
chạy 1.py -> xem file .yaml và chỉnh lại nếu bị sai
chạy 2.py
chạy 3.py
chạy 4.py
chạy 5.py
==========================HƯỠNG DẪN CHẠY====================
