#ifndef OOP_COMMAND_H
#define OOP_COMMAND_H
#include "document.h"

struct Acommand {
    virtual ~Acommand() = default;
    virtual void UnExecute() = 0;


protected:
    std::shared_ptr<document> doc_;
};

struct InsertCommand : public Acommand {
public:
    void UnExecute() override;

    InsertCommand(std::shared_ptr<document>& doc);


};

struct DeleteCommand : public Acommand {
public:
    DeleteCommand(std::shared_ptr<figure>& newFigure, uint32_t newIndex,std::shared_ptr<document>& doc);
    void UnExecute() override;

private:
    std::shared_ptr<figure> figure_;
    uint32_t index_;
};
//====================================realize=============================
void InsertCommand::UnExecute() {
    doc_->RemoveLast();
}

InsertCommand::InsertCommand(std::shared_ptr<document> &doc) {
    doc_ = doc;
}

DeleteCommand::DeleteCommand(std::shared_ptr<figure> &newFigure, uint32_t newIndex, std::shared_ptr<document> &doc) {
    doc_ = doc;
    figure_ = newFigure;
    index_ = newIndex;
}

void DeleteCommand::UnExecute() {
    doc_->InsertIndex(figure_,index_);
}
#endif //OOP_COMMAND_H
