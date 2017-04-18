import java.util.*;
import java.util.regex.Pattern;
import AddressBook.*;


public class Main {

	public static boolean is_only_digit(String to_check_) {
		if(Pattern.matches("[a-zA-Z]+", to_check_)==false){
			return true;
		}
		return false;
	}
	
	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);
		AddressBookController abc=new AddressBookController();
		
		
		abc.load();
		while(true){
			System.out.println("--------------");
			System.out.println("1. Addressbook");
			System.out.println("2. Sms");
			System.out.println("3. Call");
			System.out.println("4. Quit");
			System.out.println("--------------");
			
			String command=sc.nextLine();
			
			if(command.equals("quit")){
				System.out.println("correct!\n");
			}
			if (command.equals("1") || command.equals("Addressbook") || command.equals("AddressBook") || command.equals("addressbook")) {
				while (true) {
					//��������. back�̶�� ����ڰ� ������ ������ ���� ������ ����
					System.out.println("1. Save   2. Load   3.View   4.Back");
					String input = sc.nextLine();
					//����. 
					if (input.equals("save") || input.equals("Save") || input.equals("SAVE") || input.equals("1")) {
						abc.save();
						System.out.println("saved!");
						//�����ߴٰ� �˷���
					} 
					//�ҷ�����
					else if (input.equals("load") || input.equals("Load") || input.equals("LOAD") || input.equals("2")) {
						abc.load();
						System.out.println("loaded!");
						//�ҷ��Դٰ� �˷���
					} 
					//��ȭ��ȣ�� ����.
					else if (input.equals("view") || input.equals("View") || input.equals("VIEW") || input.equals("3")) {
						while (true) {
							//1���� �����ϴ� �ε��� + �̸�. ó���� ���ã���� ����� ����ϰ� �� �Ŀ� ���� �����
							abc.print();
							//�ε����� �Է��Ͽ� Ư���ι��� ���ų� /�˻� �߰� ����\ ����. back ��ɾ�� ���ư���
							System.out.println("Type index to view detail. special command : |Delete Search Add Back|");
							String input2=sc.nextLine();
							//���� ���ڷθ� �̷���� �Է��� �޾��� ��
							if(is_only_digit(input2)){
								int index=Integer.parseInt(input2);
								//�ε����� Ÿ�缺 �˻�
								if(index<1 || index>abc.addresslist.size()){
									System.out.println("Wrong Index! type again");
									continue;
								}

								// �ε����� 1���� n�������� ���� �迭���� 0���� n-1�����Ƿ� -1����
								index--;
								// �ش� �ε����� �ι��� ������
								abc.addresslist.get(index).display();
								// ���߿� ����� ��ȭ�� ���ڱ�ɵ� �߰��� �� ����
								System.out.println("1.Edit    2.Delete   3.Back");

								String input3 = sc.nextLine();
								// �������
								if (input3.equals("edit") || input3.equals("Edit") || input3.equals("EDIT") || input3.equals("1")) {
									abc.edit(index);
								}
								// �������
								else if (input3.equals("Delete") || input3.equals("delete") || input3.equals("DELETE") || input3.equals("2")) {
									abc.delete(index);
								}
								// ���ư���
								else if (input3.equals("back") || input3.equals("Back") || input3.equals("BACK") || input3.equals("3")) {
									break;
								}

							}
							else if(input2.equals("Delete") || input2.equals("delete") || input2.equals("DELETE")){
								System.out.println("Type index to delete");
								String input3=sc.nextLine();
								//���� ���ڷθ� �̷���� �Է��� �޾��� ��
								if(is_only_digit(input3)){
									int index=Integer.parseInt(input3);
									//�ε����� Ÿ�缺 �˻�
									if(index<1 || index>abc.addresslist.size()){
										System.out.println("Wrong Index! type again");
										continue;
									}
									// �ε����� 1���� n�������� ���� �迭���� 0���� n-1�����Ƿ� -1����
									index--;
									abc.delete(index);
								}
								
							}
							else if(input2.equals("Search") || input2.equals("search") || input2.equals("SEARCH")){
								System.out.println("Type name or PhoneNumber");
								String input3=sc.nextLine();
								//�̸����� ã��
								int searchresult=abc.SearchByName(input3);
								//��ã���� ��ȭ��ȣ�� ã��
								if(searchresult==-1) searchresult=abc.SearchByphone(input3);
								//�׷��� ��ã���� �ƿ� ��ã������
								if(searchresult==-1) System.out.println("Can't find");
								else{
									//�˻������ int���� �ε����� ���Ϲ���
									
									// �ش� �ε����� �ι��� ������
									abc.addresslist.get(searchresult).display();
									// ���߿� ����� ��ȭ�� ���ڱ�ɵ� �߰��� �� ����
									System.out.println("1.Edit    2.Delete   3.Back");
									String input4 = sc.nextLine();
									// �������
									if (input4.equals("edit") || input4.equals("Edit") || input4.equals("EDIT") || input4.equals("1")) {
										abc.edit(searchresult);
									}
									// �������
									else if (input4.equals("Delete") || input4.equals("delete")|| input4.equals("DELETE") || input4.equals("2")) {
										abc.delete(searchresult);
									}
										// ���ư���
									else if (input4.equals("back") || input4.equals("Back") || input4.equals("BACK") || input4.equals("3")) {
										//break;
									}
								}
							}
			
							else if(input2.equals("add") || input2.equals("Add") || input2.equals("ADD")){
								System.out.println("Type name");
								String name=sc.nextLine();
								System.out.println("Type phone");
								String phone=sc.nextLine();
								abc.add(name, phone, false);
							}
							else if(input2.equals("back") || input2.equals("Back") || input2.equals("BACK")){
								break;
							}
						}
					} else if (input.equals("back") || input.equals("Back") || input.equals("BACK") || input.equals("4")) {
						break;
					}
				}
			} else if (command.equals("2")  || command.equals("SMS") || command.equals("Sms")||command.equals("sms")){
				
			}
			else if (command.equals("3")  || command.equals("call") || command.equals("Call")){
				
			}
			else if (command.equals("4")  || command.equals("quit") || command.equals("Quit")) {
				break;
			}
			
		}
		
	}





}
