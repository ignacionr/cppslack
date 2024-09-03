#include "cppslack.hpp"

int main() {
    std::string slackHook = std::getenv("INNERACTIVE_SLACK_HOOK");
    ignacionr::cppslack slack(slackHook);

    // Simple message
slack.send_message(
    "• *Results for the day:*\n"
    "    ◦ only catching up now, sorry for the delay on starting the daily standup report\n\n"
    "• *Blockers:*\n"
    "    ◦ Roman’s availability for an introductory meeting\n\n"
    "• *Next steps:*\n"
    "    ◦ find out the fastest path to adding value to both Inneractive and Truey\n\n"
    "• *Note/comments:*\n"
    "    ◦ All comments are welcome"
);

    // Message with a custom username
    // slack.send_message("Hello from custom user!", "CustomUser");

    // Message to a specific channel
    // slack.send_message("Hello, specific channel!", "CustomUser", "#your-channel");

    // Message with attachments
    // std::string attachments = "[{\"text\": \"This is an attachment.\"}]";
    // slack.send_message_with_attachments("Message with attachment", attachments);

    return 0;
}
