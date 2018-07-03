#ifndef __JSVAR_H__
#define __JSVAR_H__

enum JSVarType {
	NUMBER = 0,
	STRING,
	ARRAY,
	OBJECT,
	FUNCTION,
};

class JSVar {
	private:
		JSVarType objectType;
	public:
		JSVar();
		JSVar(JSVarType type);

		JSVarType getType();
		void setType(JSVarType type);
};

#endif
