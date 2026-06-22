#include "../include/gl_expr.h"
#include <cctype>
#include <cstdlib>

namespace GLExpr {

struct Parser {
    const char* p;

    void skipSpaces() { while (*p == ' ' || *p == '\t') p++; }

    bool parseNumber(double& out) {
        skipSpaces();
        char* end = nullptr;
        out = strtod(p, &end);
        if (end == p) return false;
        p = end;
        return true;
    }

    bool parseFactor(double& out) {
        skipSpaces();
        if (*p == '(') {
            p++;
            if (!parseExpr(out)) return false;
            skipSpaces();
            if (*p != ')') return false;
            p++;
            return true;
        }
        if (*p == '-') {
            p++;
            if (!parseFactor(out)) return false;
            out = -out;
            return true;
        }
        if (*p == '+') {
            p++;
            return parseFactor(out);
        }
        return parseNumber(out);
    }

    bool parseTerm(double& out) {
        if (!parseFactor(out)) return false;
        for (;;) {
            skipSpaces();
            if (*p == '*') {
                p++;
                double rhs;
                if (!parseFactor(rhs)) return false;
                out *= rhs;
            } else if (*p == '/') {
                p++;
                double rhs;
                if (!parseFactor(rhs)) return false;
                if (rhs == 0.0) return false;
                out /= rhs;
            } else {
                break;
            }
        }
        return true;
    }

    bool parseExpr(double& out) {
        if (!parseTerm(out)) return false;
        for (;;) {
            skipSpaces();
            if (*p == '+') {
                p++;
                double rhs;
                if (!parseTerm(rhs)) return false;
                out += rhs;
            } else if (*p == '-') {
                p++;
                double rhs;
                if (!parseTerm(rhs)) return false;
                out -= rhs;
            } else {
                break;
            }
        }
        return true;
    }
};

bool evaluate(const std::string& expr, double& out) {
    if (expr.empty()) return false;
    Parser parser;
    parser.p = expr.c_str();
    if (!parser.parseExpr(out)) return false;
    parser.skipSpaces();
    return *parser.p == '\0';
}

} // namespace GLExpr
