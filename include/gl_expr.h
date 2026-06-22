#ifndef GL_EXPR_H
#define GL_EXPR_H

#include <string>

namespace GLExpr {
    bool evaluate(const std::string& expr, double& out);
}

#endif // GL_EXPR_H
