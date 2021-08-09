#ifndef __NG_STD_STRING_H__
#define __NG_STD_STRING_H__
ng_i8_t ng_std_str_cmp(register ng_i8_p a,register ng_i8_p b)
{
	for(ng_u64_t i=0;a[i]&&b[i];i++) if(a[i]!=b[i]) return 0;
	return 1;
}

ng_u64_t ng_std_str_len(register ng_i8_p a)
{
	ng_u64_t i=0;
	for(;a[i];i++){};
	return i;
}

ng_i8_p ng_std_str_cpy(register ng_i8_p a)
{
	register ng_u64_t len=ng_std_str_len(a);
	register ng_i8_p b=ng_mem_alloc(len);
	for(ng_u64_t i=0;i<len;i++) b[i]=a[i];
	return b;
}

void ng_std_str_fill(register ng_i8_p a,register ng_u64_t n,register ng_i8_t b)
{
	ng_mem_fill(a,n,b);
	a[n]='\0';
}

ng_i8_p ng_std_str_cat(register ng_i8_p a,register ng_i8_p b)
{
	ng_u64_t la=ng_std_str_len(a);
	ng_u64_t lb=ng_std_str_len(b);
	ng_i8_p res=ng_mem_alloc(la+lb);
	ng_u64_t i=0;
	for(;i<la;i++) res[i]=a[i];
	for(ng_u64_t j=0;j<lb;j++,i++) res[i]=b[j];
	res[i]='\0';
	return res;
}
#endif/* __NG_STD_STRING_H__ */