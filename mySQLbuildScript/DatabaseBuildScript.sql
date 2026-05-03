
use inventoryManagement;
drop table if exists WorkOrder;
drop table if exists Job;
drop table if exists Customer;
drop table if exists ItemComponentItems;
drop table if exists Item;
drop database if exists inventoryManagement;


create database inventoryManagement;
use inventoryManagement;

create table Item(
	itemID int primary key auto_increment,
    itemName varchar(50),
    itemDescription varchar(150),
    itemValue double,
    itemQuantity int,
    resourceCode int
);
insert into Item (itemName, itemDescription, itemValue, itemQuantity, resourceCode) values
('Nails', 'hit these with hammers', 0.02, 243, 0),
('Screws', 'install with screwdrivers', 0.08, 134, 0),
('Planks', 'flat boards for making things', 45.04, 35, 0),
('End Table', '2 ft x 3 ft, 2.5 ft tall', 87.45, 2, 2),
('Outdoor Chair', 'single person, outdoor', 73.45, 2, 2)
;

create table Customer(
	customerID int unsigned primary key auto_increment,
    customerName varchar(100),
    customerAddress varchar(300),
    customerPhone varchar(15)
);
insert into Customer (customerName, customerAddress, customerPhone) values
('ABC furniture', '234 broadroad dr, townsville IL 43210', '555-555-5555'),
('Super Mark It', '12 Prarie Ridge ave, placeburg, MN, 51021', '555-333-1111')
;

create table Job(
	jobID int primary key auto_increment,
    jobCustomer int unsigned,
    constraint job_CustomerID_fk foreign key (jobCustomer) references Customer(customerID)
);
insert into Job(jobCustomer) values
(1), (2);

create table WorkOrder(
	workOrderID int primary key auto_increment,
    workOrderJobNumber int,
    workOrderOrderedItem int,
    workOrderItemQuantity int,
    constraint workOrder_jobID_fk foreign key (workOrderJobNumber) references Job (jobID),
    constraint workOrder_itemID_fk foreign key (workOrderOrderedItem) references Item (itemID)
);
insert into WorkOrder (workOrderJobNumber, workOrderOrderedItem, workOrderItemQuantity) values
(1, 4, 5),
(1, 5, 3),
(2, 4, 19)
;

create table ItemComponentItems(
    itemID int,
    component int,
    componentPerItemRatio double,
    primary key (itemID, component),
    foreign key (itemID) references Item(itemID),
    foreign key (component) references Item(itemID)
);
insert into ItemComponentItems(itemID, component, componentPerItemRatio) values
(4, 1, 4.0),
(4, 2, 8.0),
(4, 3, 0.33),
(5, 1, 12.0),
(5, 2, 22.0),
(5, 3, 0.60)
;