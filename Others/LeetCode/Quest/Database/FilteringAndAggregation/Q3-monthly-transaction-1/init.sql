CREATE TYPE transaction_state AS ENUM ('approved', 'declined');

create table if not exists transactions (id int, country varchar(4), state transaction_state, amount int, trans_date date);
truncate table transactions;
insert into transactions (id, country, state, amount, trans_date) values ('121', 'US', 'approved', '1000', '2018-12-18');
insert into transactions (id, country, state, amount, trans_date) values ('122', 'US', 'declined', '2000', '2018-12-19');
insert into transactions (id, country, state, amount, trans_date) values ('123', 'US', 'approved', '2000', '2019-01-01');
insert into transactions (id, country, state, amount, trans_date) values ('124', 'DE', 'approved', '2000', '2019-01-07');
