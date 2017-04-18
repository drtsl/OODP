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
					//루프돌림. back이라고 사용자가 원하지 않으면 절대 깨지지 않음
					System.out.println("1. Save   2. Load   3.View   4.Back");
					String input = sc.nextLine();
					//저장. 
					if (input.equals("save") || input.equals("Save") || input.equals("SAVE") || input.equals("1")) {
						abc.save();
						System.out.println("saved!");
						//저장했다고 알려줌
					} 
					//불러오기
					else if (input.equals("load") || input.equals("Load") || input.equals("LOAD") || input.equals("2")) {
						abc.load();
						System.out.println("loaded!");
						//불러왔다고 알려줌
					} 
					//전화번호부 보기.
					else if (input.equals("view") || input.equals("View") || input.equals("VIEW") || input.equals("3")) {
						while (true) {
							//1부터 시작하는 인덱스 + 이름. 처음엔 즐겨찾기한 사람들 출력하고 그 후엔 전부 출력함
							abc.print();
							//인덱스를 입력하여 특정인물을 보거나 /검색 추가 삭제\ 가능. back 명령어로 돌아가기
							System.out.println("Type index to view detail. special command : |Delete Search Add Back|");
							String input2=sc.nextLine();
							//오직 숫자로만 이루어진 입력을 받았을 때
							if(is_only_digit(input2)){
								int index=Integer.parseInt(input2);
								//인덱스의 타당성 검사
								if(index<1 || index>abc.addresslist.size()){
									System.out.println("Wrong Index! type again");
									continue;
								}

								// 인덱스는 1부터 n까지지만 실제 배열에선 0부터 n-1까지므로 -1해줌
								index--;
								// 해당 인덱스의 인물을 보여줌
								abc.addresslist.get(index).display();
								// 나중엔 여기다 전화나 문자기능도 추가할 수 있음
								System.out.println("1.Edit    2.Delete   3.Back");

								String input3 = sc.nextLine();
								// 편집기능
								if (input3.equals("edit") || input3.equals("Edit") || input3.equals("EDIT") || input3.equals("1")) {
									abc.edit(index);
								}
								// 삭제기능
								else if (input3.equals("Delete") || input3.equals("delete") || input3.equals("DELETE") || input3.equals("2")) {
									abc.delete(index);
								}
								// 돌아가기
								else if (input3.equals("back") || input3.equals("Back") || input3.equals("BACK") || input3.equals("3")) {
									break;
								}

							}
							else if(input2.equals("Delete") || input2.equals("delete") || input2.equals("DELETE")){
								System.out.println("Type index to delete");
								String input3=sc.nextLine();
								//오직 숫자로만 이루어진 입력을 받았을 때
								if(is_only_digit(input3)){
									int index=Integer.parseInt(input3);
									//인덱스의 타당성 검사
									if(index<1 || index>abc.addresslist.size()){
										System.out.println("Wrong Index! type again");
										continue;
									}
									// 인덱스는 1부터 n까지지만 실제 배열에선 0부터 n-1까지므로 -1해줌
									index--;
									abc.delete(index);
								}
								
							}
							else if(input2.equals("Search") || input2.equals("search") || input2.equals("SEARCH")){
								System.out.println("Type name or PhoneNumber");
								String input3=sc.nextLine();
								//이름으로 찾음
								int searchresult=abc.SearchByName(input3);
								//못찾으면 전화번호로 찾음
								if(searchresult==-1) searchresult=abc.SearchByphone(input3);
								//그래도 못찾으면 아예 못찾은거임
								if(searchresult==-1) System.out.println("Can't find");
								else{
									//검색결과는 int형의 인덱스로 리턴받음
									
									// 해당 인덱스의 인물을 보여줌
									abc.addresslist.get(searchresult).display();
									// 나중엔 여기다 전화나 문자기능도 추가할 수 있음
									System.out.println("1.Edit    2.Delete   3.Back");
									String input4 = sc.nextLine();
									// 편집기능
									if (input4.equals("edit") || input4.equals("Edit") || input4.equals("EDIT") || input4.equals("1")) {
										abc.edit(searchresult);
									}
									// 삭제기능
									else if (input4.equals("Delete") || input4.equals("delete")|| input4.equals("DELETE") || input4.equals("2")) {
										abc.delete(searchresult);
									}
										// 돌아가기
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
