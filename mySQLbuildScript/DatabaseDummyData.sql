use inventoryManagement;

insert into Item (itemName, itemDescription, itemValue, itemQuantity, resourceCode) values
('Nails', 'hit these with hammers', 0.02, 243, 0),
('Screws', 'install with screwdrivers', 0.08, 134, 0),
('Planks', 'flat boards for making things', 45.04, 35, 0),
('End Table', '2 ft x 3 ft, 2.5 ft tall', 87.45, 2, 2),
('Outdoor Chair', 'single person, outdoor', 73.45, 2, 2)
;
insert into Customer (customerName, customerAddress, customerPhone) values
('ABC furniture', '234 broadroad dr, townsville IL 43210', '555-555-5555'),
('Super Mark It', '12 Prarie Ridge ave, placeburg, MN, 51021', '555-333-1111')
;
insert into Job(jobCustomer) values
(1), (2);
insert into WorkOrder (workOrderJobNumber, workOrderOrderedItem, workOrderItemQuantity) values
(1, 4, 5),
(1, 5, 3),
(2, 4, 19)
;
insert into ItemComponentItems(itemID, component, componentPerItemRatio) values
(4, 1, 4.0),
(4, 2, 8.0),
(4, 3, 0.33),
(5, 1, 12.0),
(5, 2, 22.0),
(5, 3, 0.60)
;