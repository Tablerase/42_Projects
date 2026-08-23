create table if not exists orders (order_number int, customer_number int);
truncate table orders;
-- test 1
-- insert into orders (order_number, customer_number) values ('1', '1');
-- insert into orders (order_number, customer_number) values ('2', '2');
-- insert into orders (order_number, customer_number) values ('3', '3');
-- insert into orders (order_number, customer_number) values ('4', '3');
-- test 2
insert into orders (order_number, customer_number) values ('3', '5');
insert into orders (order_number, customer_number) values ('5', '1');
insert into orders (order_number, customer_number) values ('6', '5');
insert into orders (order_number, customer_number) values ('7', '4');
insert into orders (order_number, customer_number) values ('8', '6');
insert into orders (order_number, customer_number) values ('9', '2');
insert into orders (order_number, customer_number) values ('10', '4');
insert into orders (order_number, customer_number) values ('11', '16');
insert into orders (order_number, customer_number) values ('12', '3');
insert into orders (order_number, customer_number) values ('13', '5');
insert into orders (order_number, customer_number) values ('14', '3');
insert into orders (order_number, customer_number) values ('15', '16');
