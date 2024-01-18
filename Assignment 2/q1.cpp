//#include "xml.h"
//
//int Function::StringLength(const char* str)
//
//{
//	int len = 0;
//	if (str == nullptr)
//	{
//		return len;
//	}
//
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		len++;
//	}
//	return len;
//}
//
//void Function::StringCopy(char*& cpy, const char* og)
//
//{
//	int size = StringLength(og);
//	if (cpy != NULL)
//		delete[]cpy;
//	cpy = new char[size + 1];
//	int i;
//	for (i = 0; i < size; i++)
//	{
//		cpy[i] = og[i];
//	}
//	cpy[i] = '\0';
//
//}
//
//int main()
//{
//
//	Stack<XMLDATA> stack;
//	ifstream txt_file;
//	txt_file.open("xml.txt");
//	if (txt_file)
//	{
//		char Input[100];
//		int counter = -1;
//		int size = 1;
//		int flag;
//
//
//		int A;
//		int B;
//		int i;
//
//
//		int X;
//		int Y;
//
//
//		bool flag1 = false;
//		while (!txt_file.eof() && size > 0)
//		{
//			XMLDATA xml_obj;
//
//
//			X = -1;
//			Y = -1;
//			A = -1;
//			B = -1;
//
//			flag = -1;
//
//			char Tag_txt[50] = { 0 };
//			char txt_bw_Tags[50] = { 0 };
//			txt_file.getline(Input, 100);
//			counter++;
//			i = 0;
//			size = Function::StringLength(Input);
//			if (size > 0)
//			{
//				if (Input[i] == '<')
//				{
//
//					// For checking XML Prolong
//					if (Input[i + 1] == '?')
//					{
//						for (int j = i; Input[j] != '\0'; j++)
//						{
//							if (j <= 1)
//							{
//								Tag_txt[j] = Input[j];
//								if (j == 1)
//									Tag_txt[++j] = '\0';
//
//							}
//							if (Input[j] == '>')
//							{
//								txt_bw_Tags[++i] = Input[j];
//								if (Input[j - 1] == '?')
//								{
//									txt_bw_Tags[--i] = Input[j - 1];
//									txt_bw_Tags[i = i + 2] = '\0';
//
//								}
//							}
//						}
//
//						if (counter == 0)
//						{
//							xml_obj.Set_line_Number(counter);
//							xml_obj.Set_text(Tag_txt);
//							stack.push(xml_obj);
//							flag1 = stack.compare_T(Tag_txt);
//							if (flag1 == false)
//							{
//								cout << " TAG MISMATCH ERROR !\n";
//								xml_obj.Print();
//							}
//							else
//							{
//
//								stack.pop(xml_obj);
//							}
//
//						}
//						else
//						{
//							xml_obj.Set_text("Prolong ERROR");
//							cout << "ERROR !\n";
//							xml_obj.Print();
//
//						}
//					}
//					else if ((Input[i + 1] >= 'A' && Input[i + 1] <= 'Z') || (Input[i + 1] >= 'a' && Input[i + 1] <= 'z'))
//						{
//
//							// For checking Simple XML tags
//
//							int j;
//							for (j = i + 1; Input[j] != '\0'; j++)
//							{
//								if (Input[j] != '<')
//								{
//
//									//For checking whether a tag have an attribute or not
//
//									if (Input[j] == 32 && B == -1)
//									{
//										A = -1;
//										int k;
//										for (k = j + 1; Input[k] != '\0'; k++)
//										{
//											if (Input[k] == 34 && Input[k - 1] == '=')
//											{
//												for (int m = k + 1; Input[m] != '>'; m++)
//												{
//
//													if (Input[m] == 34 && Input[m + 1] == '>')
//													{
//														X = 0;
//														k = m;
//														break;
//													}
//													else
//														txt_bw_Tags[++A] = Input[m];
//
//												}
//												txt_bw_Tags[++A] = '\0';
//												if (X != 0)
//												{
//													cout << " ERROR ! \n";
//													cout << " attribute " << txt_bw_Tags << " at line number " << counter << endl;
//													cout << " --->> attribute is not closed or opened properly <<--- \n\n ";
//												}
//												else
//													break;
//											}
//											else
//												if (Input[k] == 34 && Input[k + 1] == '>')
//												{
//													cout << " ERROR ! \n";
//													cout << " attribute " << txt_bw_Tags << " at line number " << counter << endl;
//													cout << " --->> attribute is not closed or opened properly <<--- \n\n ";
//													break;
//												}
//												else
//													if (Input[k] == 39 && Input[k - 1] == '=')
//													{
//
//														for (int m = k + 1; Input[m] != '>'; m++)
//														{
//															if (Input[m] == 39 && Input[m + 1] == '>')
//															{
//																X = 0;
//																k = m;
//																break;
//
//															}
//															else
//																txt_bw_Tags[++A] = Input[m];
//														}
//														txt_bw_Tags[++A] = '\0';
//														if (X != 0)
//														{
//															cout << " ERROR ! \n";
//															cout << " at line number " << counter << endl;
//															cout << " --->> attribute is not closed or opened properly <<--- \n\n ";
//
//														}
//													}
//													else
//														if (Input[k] == 34 && Input[k + 1] == '>')
//														{
//															cout << " ERROR ! \n";
//															cout << " attribute " << txt_bw_Tags << " at line number " << counter << endl;
//															cout << " --->> attribute is not closed or opened properly <<--- \n\n ";
//														}
//														else
//															if (Input[k] == '>' && (Input[k - 1] >= 'a' && Input[k - 1] <= 'z') || (Input[k - 1] >= 'A' && Input[k - 1] <= 'Z'))
//															{
//																break;
//															}
//										}
//										if (Input[k] == '>')
//											j = k - 1;
//										else
//											j = k;
//									}
//									else
//										if (Input[j] == '>')
//										{
//											flag++;
//											X = -1;
//											B = 0;
//										}
//										else
//										{
//
//											if (flag == 0)
//											{
//												X++;
//												txt_bw_Tags[X] = Input[j];
//
//											}
//											else
//											{
//												Y++;
//												Tag_txt[Y] = Input[j];
//											}
//
//										}
//
//								}
//								else
//									break;
//							}
//							if (X != 0)
//								txt_bw_Tags[++X] = '\0';
//							Tag_txt[++Y] = '\0';
//
//							xml_obj.Set_line_Number(counter);
//							xml_obj.Set_text(Tag_txt);
//							stack.push(xml_obj);
//
//
//							if (flag != 0)
//							{
//								cout << " ERROR ! ";
//								xml_obj.Print();
//								cout << "--->> ' > ' sign is missing for that tag <<--- \n\n ";
//
//							}
//
//							else
//							{
//								if (X != 0)
//								{
//									if (txt_bw_Tags[0] != NULL)
//									{
//
//										//For checking whether tag is closed or not
//
//										X = 0;
//										if (Input[j + 1] == '/')
//										{
//											for (j = j + 2; Input[j] != '\0'; j++)
//											{
//												if (Input[j] != '>')
//													Tag_txt[X++] = Input[j];
//												else
//													break;
//											}
//											flag1 = stack.compare_T(Tag_txt);
//											if (flag1 == false)
//											{
//												cout << " TAG MISMATCH ERROR ! ";
//												xml_obj.Print();
//												cout << "--->> A closing tag occurs without any Opening tag <<--- \n\n ";
//											}
//											else
//											{
//
//
//												stack.pop(xml_obj);
//											}
//										}
//										else
//										{
//											cout << " ERROR ! ";
//											xml_obj.Print();
//											cout << "--->> '/' sign is missing for that closing tag <<--- \n\n ";
//										}
//									}
//
//								}
//
//
//							}
//
//						}
//					else if (Input[i + 1] == '!' && Input[i + 2] == '-' && Input[i + 3] == '-')
//							{
//								//For checking Comments in XML
//
//								int j;
//								for (j = i + 4; Input[j] != '\0'; j++)
//								{
//									if (Input[j] == '-' && Input[j + 1] == '-' && Input[j + 2] == '>' && Input[j + 3] == '\0')
//									{
//										flag++;
//										break;
//									}
//									else
//										if (Input[j] != '-' && Input[j] != '>')
//											Tag_txt[j - 4] = Input[j];
//								}
//								Tag_txt[j - 1] = '\0';
//								if (flag != 0)
//								{
//									xml_obj.Set_line_Number(counter);
//									xml_obj.Set_text(Tag_txt);
//									cout << " ERROR ! ";
//									xml_obj.Print();
//									cout << "--->> XML Comment is incomplete without its symbols <<--- \n\n ";
//								}
//								else
//								{
//									cout << Tag_txt << endl;
//								}
//							}
//				    else if (Input[i + 1] == '/')
//								{
//									int j;
//									X = -1;
//									for (j = i + 2; Input[j] != '\0'; j++)
//									{
//										if (Input[j] != '>')
//											Tag_txt[++X] = Input[j];
//										else
//											break;
//									}
//									Tag_txt[++X] = '\0';
//									xml_obj.Set_line_Number(counter);
//									xml_obj.Set_text(Tag_txt);
//									flag1 = stack.compare_T(Tag_txt);
//									if (flag1 == false)
//									{
//										cout << " TAG MISMATCH ERROR !";
//										cout << " at line number " << counter << " with tag text " << Tag_txt << endl;
//										cout << "--->> A closing tag occur in xml Code without any Opening tag <<--- \n\n ";
//									}
//									else
//									{
//
//										stack.pop(xml_obj);
//
//									}
//								}
//				    else
//								{
//									cout << " ERROR ! ";
//									xml_obj.Print();
//									cout << "--->> '/' sign is missing for that closing tag <<--- \n\n ";
//								}
//				}
//			}
//		}
//
//
//		// Show those tags who don't have any closing end
//		bool check = stack.isEmpty();
//		if (!check)
//		{
//			XMLDATA obj_1;
//			cout << "The Following Opening tags in XML Code do not have any closing tags\n";
//			while (!stack.isEmpty())
//			{
//				stack.Top(obj_1);
//				obj_1.Print();
//				stack.pop(obj_1);
//			}
//		}
//
//		else
//		{
//
//			cout << "No errors occurred in the given file\n";
//		}
//		txt_file.close();
//	}
//	else
//		cout << "Error occurred opening the file\n";
//
//
//	return 0;
//}