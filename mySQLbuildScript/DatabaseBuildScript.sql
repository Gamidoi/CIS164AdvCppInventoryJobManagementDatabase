
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

create table Customer(
	customerID int unsigned primary key auto_increment,
    customerName varchar(100),
    customerAddress varchar(300),
    customerPhone varchar(15)
);

create table Job(
	jobID int primary key auto_increment,
    jobCustomer int unsigned,
    constraint job_CustomerID_fk foreign key (jobCustomer) references Customer(customerID)
);

create table WorkOrder(
	workOrderID int primary key auto_increment,
    workOrderJobNumber int,
    workOrderOrderedItem int,
    constraint workOrder_jobID_fk foreign key (workOrderJobNumber) references Job (jobID),
    constraint workOrder_itemID_fk foreign key (workOrderOrderedItem) references Item (itemID)
);

create table ItemComponentItems(
    itemID int,
    component int,
    componentPerItemRatio double,
    primary key (itemID, component),
    foreign key (itemID) references Item(itemID),
    foreign key (component) references Item(itemID)
);